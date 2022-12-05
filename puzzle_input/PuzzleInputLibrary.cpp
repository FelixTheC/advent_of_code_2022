//
// Created by felix on 05.12.22.
//

#include "PuzzleInputLibrary.hpp"


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
