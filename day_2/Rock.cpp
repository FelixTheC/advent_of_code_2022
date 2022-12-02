//
// Created by felix on 02.12.22.
//

#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"


int Rock::play(Hand &rhs)
{
    std::string_view other_name = rhs.get_name();

    if(other_name == "Rock")
    {
        return Hand::DRAW + this->get_value();
    }

    if(other_name == "Scissors")
    {
        return Hand::WIN + this->get_value();
    }

    if(other_name == "Paper")
    {
        return Hand::LOST + this->get_value();
    }
}

Hand *Rock::draw()
{
    return new Rock();
}

Hand *Rock::lose()
{
    return new Paper();
}

Hand *Rock::win()
{
    return new Scissors();
}
