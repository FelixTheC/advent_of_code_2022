//
// Created by felix on 05.12.22.
//

#ifndef PUZZLE_INPUT_PUZZLEINPUTLIBRARY_HPP
#define PUZZLE_INPUT_PUZZLEINPUTLIBRARY_HPP

#include <string_view>
#include <vector>
#include <fstream>

namespace puzzle
{
    [[nodiscard]] std::vector<std::string> file_reader(const std::string &file_name);
}


#endif //PUZZLE_INPUT_PUZZLEINPUTLIBRARY_HPP
