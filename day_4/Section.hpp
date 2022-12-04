//
// Created by felix on 04.12.22.
//

#ifndef DAY_4_SECTION_HPP
#define DAY_4_SECTION_HPP


#include <string>

struct Section
{
    int start;
    int end;

    Section() : start(0), end(0) {}
    Section(int start_, int end_) : start(start_), end(end_) {}
    explicit Section(std::string &assignemnt);

    ~Section() = default;

    bool operator==(const Section &rhs) const;

    [[nodiscard]] bool contains(const Section &rhs) const;
    [[nodiscard]] bool overlap(const Section &rhs) const;
};


#endif //DAY_4_SECTION_HPP
