#include "gtest/gtest.h"
#include "../lib/input.hpp"
#include "../section_assignments.hpp"
#include "../Section.hpp"
#include "../solution.hpp"

const std::string TEST_FILE = "/home/felix/CLionProjects/advent_of_code_2022/day_4/test_input.txt";

int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

TEST(day_4, split_line_into_pairs)
{
    auto lines = puzzle::file_reader(TEST_FILE);

    {
        auto result = split_line_by_comma(lines[0]);
        auto expected = std::pair<std::string, std::string>("2-4", "6-8");

        ASSERT_EQ(result, expected);
    }
    {
        auto result = split_line_by_comma(lines[1]);
        auto expected = std::pair<std::string, std::string>("2-3", "4-5");

        ASSERT_EQ(result, expected);
    }
    {
        auto result = split_line_by_comma(lines[2]);
        auto expected = std::pair<std::string, std::string>("5-7", "7-9");

        ASSERT_EQ(result, expected);
    }
}

TEST(day_4, create_section)
{
    auto lines = puzzle::file_reader(TEST_FILE);
    auto line_pair = split_line_by_comma(lines[0]);
    {
        auto result = Section(std::get<0>(line_pair));
        auto expected = Section(2, 4);

        ASSERT_EQ(result, expected);
    }
    {
        auto result = Section(std::get<1>(line_pair));
        auto expected = Section(6, 8);

        ASSERT_EQ(result, expected);
    }
}

TEST(day_4, section_contains_other_section)
{
    auto lines = puzzle::file_reader(TEST_FILE);

    {
        auto line_pair = split_line_by_comma(lines[0]);

        auto section_1 = Section(std::get<0>(line_pair));
        auto section_2 = Section(std::get<1>(line_pair));

        auto result = section_1.contains(section_2);
        auto expected = false;

        ASSERT_EQ(result, expected);
    }

    {
        auto line_pair = split_line_by_comma(lines[3]);

        auto section_1 = Section(std::get<0>(line_pair));
        auto section_2 = Section(std::get<1>(line_pair));

        auto result = section_1.contains(section_2);
        auto expected = true;

        ASSERT_EQ(result, expected);
    }

    {
        auto line_pair = split_line_by_comma(lines[4]);

        auto section_1 = Section(std::get<0>(line_pair));
        auto section_2 = Section(std::get<1>(line_pair));

        auto result = section_2.contains(section_1);
        auto expected = true;

        ASSERT_EQ(result, expected);
    }

}

TEST(day_4, section_overlap_other_section)
{
    {
        auto section_1 = Section(2, 4);
        auto section_2 = Section(6, 8);

        auto result = section_1.overlap(section_2);
        auto expected = false;

        ASSERT_EQ(result, expected);
    }

    {
        auto section_1 = Section(5, 7);
        auto section_2 = Section(7, 9);

        auto result = section_1.overlap(section_2);
        auto expected = true;

        ASSERT_EQ(result, expected);
    }

    {
        auto section_1 = Section(2, 6);
        auto section_2 = Section(4, 8);

        auto result = section_1.overlap(section_2);
        auto expected = true;

        ASSERT_EQ(result, expected);
    }
}

TEST(day_4, test_input_solution_part_1)
{
    auto lines = puzzle::file_reader(TEST_FILE);
    auto result = solution(lines);

    ASSERT_EQ(result, 2);
}

TEST(day_4, test_input_solution_part_2)
{
    auto lines = puzzle::file_reader(TEST_FILE);
    auto result = solution_part_2(lines);

    ASSERT_EQ(result, 4);
}
