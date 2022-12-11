#include "solution.hpp"

int main()
{
    auto monkeys = puzzle::parse_input("/home/felix/CLionProjects/advent_of_code_2022/day_11/input.txt");
    auto result = solution(monkeys, 1.0);
    std::cout << "Result is: " << result << "\n";
    return 0;
}
