//
// Created by felix on 02.12.22.
//

#ifndef DAY_2_ROCK_HPP
#define DAY_2_ROCK_HPP


#include "Hand.hpp"

class Rock : public Hand
{

public:
    Rock() : Hand(1, "Rock") {}
    int play(Hand &rhs) override;

    Hand* draw() override;
    Hand* lose() override;
    Hand* win() override;
};


#endif //DAY_2_ROCK_HPP
