#include <iostream>
#include <map>
#include <fstream>
#include "Hand.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"


std::map<std::string_view, Hand*> strategy_guide {
        std::make_pair("A", new Rock()),
        std::make_pair("X", new Rock()),
        std::make_pair("B", new Paper()),
        std::make_pair("Y", new Paper()),
        std::make_pair("C", new Scissors()),
        std::make_pair("Z", new Scissors())
};

int main()
{
    int total_score = 0;
    int ultra_total_score = 0;

    std::ifstream ifstream;
    ifstream.open("/home/felix/CLionProjects/advent_of_code_2022/day_2/input");

    if (ifstream.is_open())
    {
        while (!ifstream.eof())
        {
            std::string line;
            std::getline(ifstream, line);
            std::string_view left = line.substr(0, 1);
            std::string_view right = line.substr(2, line.size() - 1);

            auto lft = strategy_guide[left];
            auto rht = strategy_guide[right];

            auto score = rht->play(*lft);
            total_score += score;

            Hand *shape;

            if (right == "X")
            {
                shape = lft->win();
            }
            else if (right == "Y")
            {
                ultra_total_score += Hand::DRAW;
                shape = lft->draw();
            }
            else if (right == "Z")
            {
                ultra_total_score += Hand::WIN;
                shape = lft->lose();
            }

            ultra_total_score += shape->get_value();
        }
    }

    ifstream.close();

    std::cout << "Total score: " << total_score << "\n";
    std::cout << "Ultra total score: " << ultra_total_score << "\n";

    return 0;
}
