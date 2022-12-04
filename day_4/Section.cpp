//
// Created by felix on 04.12.22.
//
#include <vector>
#include "Section.hpp"

Section::Section(std::string &assignemnt)
{
    auto pos = assignemnt.find('-');

    start = std::stoi(assignemnt.substr(0, pos));
    end = std::stoi(assignemnt.substr(pos + 1, assignemnt.size()));
}

bool Section::operator==(const Section &rhs) const
{
    return this->start == rhs.start && this->end == rhs.end;
}

bool Section::contains(const Section &rhs) const
{
    return rhs.start >= this->start && rhs.end <= this->end;
}

bool Section::overlap(const Section &rhs) const
{
    std::vector<int> a {};
    std::vector<int> b {};

    for (int idx = this->start; idx <= this->end; ++idx)
    {
        a.push_back(idx);
    }

    for (int idx = rhs.start; idx <= rhs.end; ++idx)
    {
        b.push_back(idx);
    }

    std::vector<int> result {};
    std::set_intersection(a.begin(), a.end(),
                          b.begin(), b.end(),
                          std::back_inserter(result));

    return !result.empty();
}
