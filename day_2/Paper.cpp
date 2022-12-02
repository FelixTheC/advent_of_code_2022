//
// Created by felix on 02.12.22.
//

#include <iostream>
#include "Paper.hpp"
#include "Scissors.hpp"
#include "Rock.hpp"

int Paper::play(Hand &rhs)
{
    std::string_view other_name = rhs.get_name();

    if(other_name == "Rock")
    {
        return Hand::WIN + this->get_value();
    }

    if(other_name == "Scissors")
    {
        return Hand::LOST + this->get_value();
    }

    if(other_name == "Paper")
    {
        return Hand::DRAW + this->get_value();
    }
}

Hand *Paper::draw()
{
    return new Paper();
}

Hand *Paper::lose()
{
    return new Scissors();
}

Hand *Paper::win()
{
    return new Rock();
}
