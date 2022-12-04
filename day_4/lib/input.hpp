//
// Created by felix on 04.12.22.
//

#ifndef PUZZLE_INPUT_INPUT_HPP
#define PUZZLE_INPUT_INPUT_HPP

#include <string_view>
#include <vector>
#include <fstream>

namespace puzzle
{
    [[nodiscard]] std::vector<std::string> file_reader(const std::string &file_name)
    {
        std::ifstream ifstream;
        ifstream.open(file_name);

        std::vector<std::string> lines{};

        if (ifstream.is_open())
        {
            while (!ifstream.eof())
            {
                std::string line;
                std::getline(ifstream, line);
                lines.push_back(line);
            }
        }

        ifstream.close();

        return lines;
    }
}

#endif //PUZZLE_INPUT_INPUT_HPP
