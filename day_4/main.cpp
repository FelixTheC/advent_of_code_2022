#include <iostream>
#include "lib/input.hpp"
#include "solution.hpp"

const std::string INPUT_FILE = "/home/felix/CLionProjects/advent_of_code_2022/day_4/input.txt";


int main()
{
    auto lines = puzzle::file_reader(INPUT_FILE);
    // auto result = solution(lines);
    auto result = solution_part_2(lines);

    std::cout << "Result: " << result << std::endl;
    return 0;
}
