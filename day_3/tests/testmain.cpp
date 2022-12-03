//
// Created by felix on 03.12.22.
//
#include <gtest/gtest.h>
#include "../puzzle_input.hpp"
#include "../rucksack.hpp"

int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

TEST(Day3, load_input)
{
    auto lines = file_reader("/home/felix/CLionProjects/advent_of_code_2022/day_3/test_input.txt");
    ASSERT_EQ(lines.size(), 6);
}

TEST(Day3, split_compartment)
{
    {
        auto result = get_rucksack_compartment("vJrwpWtwJgWrhcsFMMfFFhFp");
        ASSERT_EQ(std::get<0>(result), "vJrwpWtwJgWr");
        ASSERT_EQ(std::get<1>(result), "hcsFMMfFFhFp");
    }

    {
        auto result = get_rucksack_compartment("jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL");
        ASSERT_EQ(std::get<0>(result), "jqHRNqRjqzjGDLGL");
        ASSERT_EQ(std::get<1>(result), "rsFMfFZSrLrFZsSL");
    }

    {
        auto result = get_rucksack_compartment("ttgJtRGJQctTZtZT");
        ASSERT_EQ(std::get<0>(result), "ttgJtRGJ");
        ASSERT_EQ(std::get<1>(result), "QctTZtZT");
    }
}

TEST(Day3, sharing_compartment)
{
    {
        auto compartment = get_rucksack_compartment("vJrwpWtwJgWrhcsFMMfFFhFp");
        auto result = find_sharing_compartment(compartment);
        ASSERT_EQ(result, "p");
    }

    {
        auto compartment = get_rucksack_compartment("jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL");
        auto result = find_sharing_compartment(compartment);
        ASSERT_EQ(result, "L");
    }

    {
        auto compartment = get_rucksack_compartment("ttgJtRGJQctTZtZT");
        auto result = find_sharing_compartment(compartment);
        ASSERT_EQ(result, "t");
    }

    {
        auto compartment = get_rucksack_compartment("CrZsJsPPZsGzwwsLwLmpwMDw");
        auto result = find_sharing_compartment(compartment);
        ASSERT_EQ(result, "s");
    }
}

TEST(Day3, sharing_compartment_of_three)
{
    {
        auto result = find_sharing_compartment("vJrwpWtwJgWrhcsFMMfFFhFp",
                                               "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
                                               "PmmdzqPrVvPwwTWBwg");
        ASSERT_EQ(result, "r");
    }

    {
        auto result = find_sharing_compartment("wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
                                               "ttgJtRGJQctTZtZT",
                                               "CrZsJsPPZsGzwwsLwLmpwMDw");
        ASSERT_EQ(result, "Z");
    }
}
