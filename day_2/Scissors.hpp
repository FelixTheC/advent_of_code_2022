//
// Created by felix on 02.12.22.
//

#ifndef DAY_2_SCISSORS_HPP
#define DAY_2_SCISSORS_HPP


#include "Hand.hpp"

class Scissors : public Hand
{
public:
    Scissors() : Hand(3, "Scissors") {}
    int play(Hand &rhs) override;

    Hand* draw() override;
    Hand* lose() override;
    Hand* win() override;
};


#endif //DAY_2_SCISSORS_HPP
