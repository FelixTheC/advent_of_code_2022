#include <iostream>
#include "elve_calories.hpp"

int main()
{
    std::string_view filename = "/home/felix/CLionProjects/advent_of_code_2022/day_1/input";
    auto all_elves_calories = get_elves_calories_from_files(filename);

    std::cout << "Number of Elves: " << all_elves_calories->size() << std::endl;

    auto sorted_elves = get_sorted_elves(all_elves_calories);
    // print_elves(sorted_elves);

    auto sum_first_three = sum_x_elves_calories(sorted_elves, 3);

    std::cout << "First Elves calories: " << std::get<1>(sorted_elves->data()[0]) << "\n";
    std::cout << "First three Elves calories: " << sum_first_three << "\n";

    return 0;
}
