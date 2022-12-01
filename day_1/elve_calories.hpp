#ifndef DAY_1_ELVE_CALORIES_HPP
#define DAY_1_ELVE_CALORIES_HPP

#include <fstream>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>
#include <memory>

using all_elves_uptr = std::unique_ptr<std::vector <std::vector<int>>>;
using elves_calories_uptr = std::unique_ptr<std::vector<std::tuple<int, int>>>;

[[nodiscard]] all_elves_uptr get_elves_calories_from_files(std::string_view filename);
[[nodiscard]] elves_calories_uptr get_sorted_elves(all_elves_uptr &all_elves);
[[nodiscard]] int sum_x_elves_calories(elves_calories_uptr &all_elves, int max_);
void print_elves(elves_calories_uptr &all_elves);

#endif //DAY_1_ELVE_CALORIES_HPP
