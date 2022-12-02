//
// Created by felix on 02.12.22.
//

#include "Scissors.hpp"
#include "Paper.hpp"
#include "Rock.hpp"

int Scissors::play(Hand &rhs)
{
    std::string_view other_name = rhs.get_name();

    if(other_name == "Rock")
    {
        return Hand::LOST + this->get_value();
    }

    if(other_name == "Scissors")
    {
        return Hand::DRAW + this->get_value();
    }

    if(other_name == "Paper")
    {
        return Hand::WIN + this->get_value();
    }
}

Hand *Scissors::draw()
{
    return new Scissors();
}

Hand *Scissors::lose()
{
    return new Rock();
}

Hand *Scissors::win()
{
    return new Paper();
}
