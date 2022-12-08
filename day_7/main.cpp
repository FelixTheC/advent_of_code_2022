#include <iostream>
#include <PuzzleInputLibrary.hpp>
#include "PathObject.hpp"
#include "solution.hpp"

const long int THRESHOLD = 100000;
const long int MARGIN = 99999;

int main()
{
    auto commands = puzzle::file_reader("/home/felix/CLionProjects/advent_of_code_2022/day_7/input.txt");
    auto root = std::make_shared<pathlib::PathObject>(pathlib::PathObject {"/"});

    solution_1(commands, root);

    std::cout << *root << "\n";

    return 0;
}
