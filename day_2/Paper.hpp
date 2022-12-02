//
// Created by felix on 02.12.22.
//

#ifndef DAY_2_PAPER_HPP
#define DAY_2_PAPER_HPP


#include "Hand.hpp"

class Paper : public Hand
{
public:
    Paper() : Hand(2, "Paper") {}
    int play(Hand &rhs) override;

    Hand* draw() override;
    Hand* lose() override;
    Hand* win() override;
};


#endif //DAY_2_PAPER_HPP
