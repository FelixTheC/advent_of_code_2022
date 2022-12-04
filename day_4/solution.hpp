//
// Created by felix on 04.12.22.
//

#ifndef DAY_4_SOLUTION_HPP
#define DAY_4_SOLUTION_HPP

#include <vector>
#include <string>
#include <tuple>
#include "section_assignments.hpp"
#include "Section.hpp"

int solution(std::vector<std::string> &lines)
{
    int result = 0;
    std::for_each(lines.begin(), lines.end(),
                  [&result](auto &line){

        auto line_pair = split_line_by_comma(line);
        auto section_1 = Section(std::get<0>(line_pair));
        auto section_2 = Section(std::get<1>(line_pair));

        if (section_1.contains(section_2) || section_2.contains(section_1))
        {
            ++result;
        }
    });

    return result;
}

int solution_part_2(std::vector<std::string> &lines)
{
    int result = 0;
    std::for_each(lines.begin(), lines.end(),
                  [&result](auto &line){

                      auto line_pair = split_line_by_comma(line);
                      auto section_1 = Section(std::get<0>(line_pair));
                      auto section_2 = Section(std::get<1>(line_pair));

                      if (section_1.overlap(section_2))
                      {
                          ++result;
                      }
                  });

    return result;
}

#endif //DAY_4_SOLUTION_HPP
