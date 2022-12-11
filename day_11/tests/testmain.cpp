#include "gtest/gtest.h"
#include "../Monkey.hpp"
#include "../helpers.hpp"
#include "../parse_input.hpp"
#include "../solution.hpp"

const std::string TEST_FILE = "/home/felix/CLionProjects/advent_of_code_2022/day_11/test_input.txt";

int main(int ac, char *av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

TEST(day_11, init_monkey_cls_with_bind_param)
{
    std::deque<Number> starting_items {79, 98};
    auto operation = std::bind(multiply<unsigned short>, std::placeholders::_1, 19);
    auto test = std::bind(monkeyTestFunc<unsigned short>, std::placeholders::_1, 23, 2, 3);

    ASSERT_NO_FATAL_FAILURE(Monkey(std::move(starting_items), operation, test));
}

TEST(day_11, a_monkey_round)
{
    std::vector<Monkey> monkeys {};

    {
        std::deque<Number> starting_items {79, 98};
        auto operation = std::bind(multiply<Number>, std::placeholders::_1, 19);
        auto test = std::bind(monkeyTestFunc<Number, std::placeholders::_1, 23, 2, 3);
        auto monkey = Monkey(std::move(starting_items), operation, test);
        monkeys.emplace_back(monkey);
    }
    {
        std::deque<Number> starting_items {54, 65, 75, 74};
        auto operation = std::bind(addition<Number>, std::placeholders::_1, 6);
        auto test = std::bind(monkeyTestFunc<Number, std::placeholders::_1, 19, 2, 0);
        auto monkey = Monkey(std::move(starting_items), operation, test);
        monkeys.emplace_back(monkey);
    }
    {
        std::deque<Number> starting_items {79, 60, 97};
        auto operation = std::bind(multiply<Number>, std::placeholders::_1, std::placeholders::_1);
        auto test = std::bind(monkeyTestFunc<Number>, std::placeholders::_1, 13, 1, 3);
        auto monkey = Monkey(std::move(starting_items), operation, test);
        monkeys.emplace_back(monkey);
    }
    {
        std::deque<Number> starting_items {74};
        auto operation = std::bind(addition<Number>, std::placeholders::_1, 3);
        auto test = std::bind(monkeyTestFunc<Number>, std::placeholders::_1, 17, 0, 1);
        auto monkey = Monkey(std::move(starting_items), operation, test);
        monkeys.emplace_back(monkey);
    }

    ASSERT_EQ(0, monkeys[0].get_inspections());

    monkeys[0].round(monkeys);
    monkeys[3].round(monkeys);

    ASSERT_EQ(2, monkeys[0].get_inspections());
    ASSERT_EQ(3, monkeys[3].get_inspections());
}

TEST(day_11, test_parse_starting_items)
{
    {
        auto result = puzzle::parse_starting_items("  Starting items: 79, 98");

        ASSERT_EQ(2, result.size());
    }

    {
        auto result = puzzle::parse_starting_items("  Starting items: 54, 65, 75, 74");

        ASSERT_EQ(4, result.size());
    }

    {
        auto result = puzzle::parse_starting_items("  Starting items: 74");

        ASSERT_EQ(1, result.size());
        ASSERT_EQ(74, result[0]);
    }
}

TEST(day_11, test_parse_operation)
{
    {
        auto operation = puzzle::parse_operation("  Operation: new = old * 19");
        ASSERT_EQ(19, operation(1));
    }

    {
        auto operation = puzzle::parse_operation("  Operation: new = old + 6");
        ASSERT_EQ(12, operation(6));
    }

    {
        auto operation = puzzle::parse_operation("  Operation: new = old + old");
        ASSERT_EQ(16, operation(8));
    }
}

TEST(day_11, parse_input_text_creates_monkeys)
{
    auto monkeys = puzzle::parse_input(TEST_FILE);
    ASSERT_EQ(4, monkeys.size());
}

TEST(day_11, expected_test_result)
{
    auto monkeys = puzzle::parse_input(TEST_FILE);
    auto result = solution(monkeys);
    ASSERT_EQ(10605, result);

    ASSERT_EQ(105, monkeys[0].get_inspections());
    ASSERT_EQ(101, monkeys[1].get_inspections());
    ASSERT_EQ(95, monkeys[2].get_inspections());
    ASSERT_EQ(7, monkeys[3].get_inspections());
}

TEST(day_11, expected_result)
{
    auto monkeys = puzzle::parse_input("/home/felix/CLionProjects/advent_of_code_2022/day_11/alt_input.txt");
    auto result = solution(monkeys);
    ASSERT_EQ(120756, result);
}
