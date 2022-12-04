//
// Created by felix on 04.12.22.
//

#ifndef DAY_4_SECTION_ASSIGNMENTS_HPP
#define DAY_4_SECTION_ASSIGNMENTS_HPP

#include <string>

std::pair<std::string, std::string> split_line_by_comma(std::string &line)
{
    auto pos = line.find(',');
    auto left = line.substr(0, pos);
    auto right = line.substr(pos + 1, line.size());
    auto res = std::pair<std::string, std::string>(left, right);
    return res;
}

#endif //DAY_4_SECTION_ASSIGNMENTS_HPP
