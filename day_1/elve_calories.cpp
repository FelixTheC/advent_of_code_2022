#include "elve_calories.hpp"


all_elves_uptr get_elves_calories_from_files(const std::string_view filename)
{
    std::ifstream ifs;
    std::string line;
    ifs.open(filename.data());
    all_elves_uptr all_elves_calories = std::make_unique<std::vector <std::vector<int>>>();

    if (ifs)
    {
        std::vector<int> elves_calories{};

        while (!ifs.eof())
        {
            std::getline(ifs, line);

            if (line.empty())
            {
                all_elves_calories->emplace_back(elves_calories);
                elves_calories.clear();
                elves_calories.shrink_to_fit();
            }
            else
            {
                int calories = std::stoi(line);
                elves_calories.emplace_back(calories);
            }
        }
    }

    ifs.close();

    return all_elves_calories;
}

elves_calories_uptr get_sorted_elves(all_elves_uptr &all_elves)
{
    elves_calories_uptr sorted_elves = std::make_unique<std::vector<std::tuple<int, int>>>();

    int idx = 0;
    std::for_each(all_elves->begin(), all_elves->end(),
                  [&sorted_elves, &idx](auto &elves_cal){

                      int elves_total_calories = std::accumulate(elves_cal.begin(), elves_cal.end(), 0);
                      auto elves = std::tuple<int, int>(idx, elves_total_calories);
                      ++idx;
                      sorted_elves->emplace_back(elves);
                  });

    std::sort(sorted_elves->begin(), sorted_elves->end(),
              [](auto &val_1, auto &val_2)
              {return std::get<1>(val_1) > std::get<1>(val_2);});

    return sorted_elves;
}

void print_elves(elves_calories_uptr  &all_elves)
{
    std::for_each(all_elves->begin(), all_elves->end(),
                  [](auto &val){
                      std::cout << "Elves #" << std::get<0>(val) << " calories: " << std::get<1>(val) << "\n";
                  });
}

int sum_x_elves_calories(elves_calories_uptr &all_elves, const int max_)
{
    auto sum_first_x = 0;
    std::for_each(all_elves->begin(), all_elves->begin() + max_,
                  [&sum_first_x](auto &val){ sum_first_x += std::get<1>(val); });

    return sum_first_x;
}
