//
// Created by felix on 08.12.22.
//

#ifndef DAY_8_SOLUTION_HPP
#define DAY_8_SOLUTION_HPP

#include <vector>
#include <string>
#include <fstream>


[[nodiscard]] std::vector<std::vector<unsigned short>> file_reader(const std::string &file_name)
{
    std::ifstream ifstream;
    ifstream.open(file_name);

    std::vector<std::vector<unsigned short>> result {};

    if (ifstream.is_open())
    {
        while (!ifstream.eof())
        {
            std::string line;
            std::vector<unsigned short> trees {};

            std::getline(ifstream, line);
            for (auto &val: line)
            {
                trees.emplace_back(std::stoi(std::string{val}));
            }

            result.emplace_back(trees);
        }
    }

    ifstream.close();

    return result;
}

bool all(const std::vector<unsigned short> &values, unsigned short tree, int &blocked_at_pos)
{
    auto result = true;
    auto counter = 0;

    for (auto &val: values)
    {
        ++counter;

        if (val >= tree)
        {
            result = false;
            break;
        }
    }

    blocked_at_pos = counter;
    return result;
}


std::vector<unsigned short> create_top(const std::vector<std::vector<unsigned short>> &map, int current_row, int current_col)
{
    std::vector<unsigned short> result {};
    for (int idx = 0; idx < current_row; ++idx)
    {
        result.emplace_back(map[idx][current_col]);
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<unsigned short> create_bottom(const std::vector<std::vector<unsigned short>> &map, int current_row, int current_col)
{
    std::vector<unsigned short> result {};
    for (int idx = current_row + 1; idx < map.size(); ++idx)
    {
        result.emplace_back(map[idx][current_col]);
    }

    return result;
}

std::vector<unsigned short> create_left(const std::vector<std::vector<unsigned short>> &map, int current_row, int current_col)
{
    std::vector<unsigned short> result {};
    for (int idx = 0; idx < current_col; ++idx)
    {
        result.emplace_back(map[current_row][idx]);
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<unsigned short> create_right(const std::vector<std::vector<unsigned short>> &map, int current_row, int current_col)
{
    std::vector<unsigned short> result {};
    for (unsigned long idx = current_col + 1; idx < map[0].size(); ++idx)
    {
        result.emplace_back(map[current_row][idx]);
    }

    return result;
}

unsigned long looper(const std::vector<std::vector<unsigned short>> &map, unsigned int &best_scenic_score)
{
    unsigned long visible_trees = 0;
    unsigned int highest_score = 0;

    for (int row_no = 1; row_no < map.size() - 1; ++row_no)
    {
        auto row = map[row_no];

        for (int idx = 1; idx < row.size() - 1; ++idx)
        {
            auto tree = row[idx];

            int top_blocked = 0;
            int bottom_blocked = 0;
            int left_blocked = 0;
            int right_blocked = 0;

            volatile bool top = all(create_top(map, row_no, idx), tree, top_blocked);
            volatile bool bottom = all(create_bottom(map, row_no, idx), tree, bottom_blocked);
            volatile bool left = all(create_left(map, row_no, idx), tree, left_blocked);
            volatile bool right = all(create_right(map, row_no, idx), tree, right_blocked);

            if (top || bottom || left || right)
            {
                ++visible_trees;
            }

            unsigned int scenic_score = top_blocked * left_blocked * right_blocked * bottom_blocked;
            if (scenic_score > highest_score)
            {
                highest_score = scenic_score;
            }
        }
    }

    visible_trees += ((map.size() - 2) * 2); // top and bottom row
    visible_trees += (map[0].size() * 2); // outer left and outer right row

    best_scenic_score = highest_score;

    return visible_trees;
}

#endif //DAY_8_SOLUTION_HPP
