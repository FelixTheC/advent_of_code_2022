#include <valarray>
#include "puzzle_input.hpp"
#include "rucksack.hpp"

void solution_1();
void solution_2();

int main()
{
    // solution_1();
    solution_2();

    return 0;
}

void solution_1()
{
    auto lines = file_reader("/home/felix/CLionProjects/advent_of_code_2022/day_3/input.txt");
    int sum = 0;

    std::for_each(lines.begin(), lines.end(),
                  [&sum](auto &line){

                      auto compartment = get_rucksack_compartment(line);
                      std::string result = find_sharing_compartment(compartment);

                      sum += PRIORITY[result];
                  });

    std::cout << "Sum priorities: " << sum << "\n";
}

void solution_2()
{
    auto lines = file_reader("/home/felix/CLionProjects/advent_of_code_2022/day_3/input.txt");
    int sum = 0;

    for(int index = 0; index < lines.size(); index+=3)
    {
        auto sub_lines = std::vector<std::string>(lines.cbegin() + index, lines.cbegin() + index + 3);
        std::string result = find_sharing_compartment(sub_lines[0], sub_lines[1], sub_lines[2]);
        sum += PRIORITY[result];
    }

    std::cout << "Sum priorities: " << sum << "\n";
}
