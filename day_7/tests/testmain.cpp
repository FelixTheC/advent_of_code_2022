#include "gtest/gtest.h"
#include "../parse_command.hpp"


int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

TEST(day_7, parse_command_cd_returns_path)
{
    {
        auto result = parse_cmd("$ cd /");
        ASSERT_EQ(result, "/");
    }

    {
        auto result = parse_cmd("$ cd a");
        ASSERT_EQ(result, "a");
    }

    {
        auto result = parse_cmd("$ cd ..");
        ASSERT_EQ(result, "..");
    }
}

TEST(day_7, parse_command_ls_returns_empty_string)
{
    auto result = parse_cmd("$ ls");
    ASSERT_TRUE(result.empty());
}

TEST(day_7, parse_command_other_returns_input)
{
    {
        auto result = parse_cmd("dir a");
        ASSERT_TRUE(result.empty());
    }

    {
        auto result = parse_cmd("14848514 b.txt");
        ASSERT_TRUE(result.empty());
    }
}

TEST(day_7, parse_into_path_object_returns_dir)
{
    {
        auto result = parse_into_path_object("dir a");
        auto expected_result = pathlib::PathObject("a");

        ASSERT_EQ(result, expected_result);
    }

    {
        auto result = parse_into_path_object("dir abcde");
        auto expected_result = pathlib::PathObject("abcde");

        ASSERT_EQ(result, expected_result);
    }
}

TEST(day_7, parse_into_path_object_returns_file_with_file_size)
{
    {
        auto result = parse_into_path_object("14848514 b.txt");
        auto expected_result = pathlib::PathObject("b.txt", 14848514);

        ASSERT_EQ(result, expected_result);
    }

    {
        auto result = parse_into_path_object("4060174 j");
        auto expected_result = pathlib::PathObject("j", 4060174);

        ASSERT_EQ(result, expected_result);
    }
}
