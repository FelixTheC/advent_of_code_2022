#include <iostream>
#include "solution.hpp"

int main()
{
    auto map = file_reader("/home/felix/CLionProjects/advent_of_code_2022/day_8/input.txt");
    unsigned int scenic_score = 0;
    auto result_1 = looper(map, scenic_score);

    std::cout << "Result 1: " << result_1 << "\n";
    std::cout << "Result 2: " << scenic_score << "\n";

    return 0;
}
