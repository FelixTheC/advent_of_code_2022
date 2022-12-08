#include "gtest/gtest.h"
#include "../solution.hpp"


int main(int ac, char *av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

const std::vector<std::vector<unsigned short>> TEST_MAP = {
        {3, 0, 3, 7, 3},
        {2, 5, 5, 1, 2},
        {6, 5, 3, 3, 2},
        {3, 3, 5, 4, 9},
        {3, 5, 3, 9, 0}
};

TEST(day_8, parse_input_to_vector)
{
    auto result = file_reader("/home/felix/CLionProjects/advent_of_code_2022/day_8/test_input.txt");
    ASSERT_EQ(result.size(), 5);

    for (auto &row: result)
    {
        ASSERT_EQ(row.size(), 5);
    }
}

TEST(day_8, loop)
{
    unsigned int tmp = 0;
    auto result = looper(TEST_MAP, tmp);

    ASSERT_EQ(result, 21);
}

TEST(day_8, scence_blocked)
{
    {
        int tmp = 0;
        std::vector<unsigned short> top {3, 5, 3};

        auto result = all(top, 5, tmp);

        ASSERT_EQ(tmp, 2);
    }

    {
        int tmp = 0;
        std::vector<unsigned short> top {3, 3};

        auto result = all(top, 5, tmp);

        ASSERT_EQ(tmp, 2);
    }

    {
        int tmp = 0;
        std::vector<unsigned short> top {3};

        auto result = all(top, 5, tmp);

        ASSERT_EQ(tmp, 1);
    }

    {
        int tmp = 0;
        std::vector<unsigned short> top {4, 9};

        auto result = all(top, 5, tmp);

        ASSERT_EQ(tmp, 2);
    }

    {
        int tmp = 0;
        std::vector<unsigned short> top {5, 3};

        auto result = all(top, 3, tmp);

        ASSERT_EQ(tmp, 1);
    }

    {
        int tmp = 0;
        std::vector<unsigned short> top {3, 5, 3};

        auto result = all(top, 5, tmp);

        ASSERT_EQ(tmp, 2);
    }
}
