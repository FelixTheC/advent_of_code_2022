//
// Created by felix on 11.12.22.
//

#ifndef DAY_11_SOLUTION_HPP
#define DAY_11_SOLUTION_HPP

#include "parse_input.hpp"

const unsigned short ROUNDS = 10000;

[[nodiscard]] unsigned long solution(std::vector<Monkey> &monkeys, float worry_reduce = 3.0)
{
    unsigned long result = 0;

    for (int round = 0; round < ROUNDS; ++round)
    {
        for (auto &monkey: monkeys)
        {
            monkey.round(monkeys, worry_reduce);
        }
    }

    std::sort(monkeys.begin(), monkeys.end(),
              [](auto val_a, auto val_b)
        {
            return val_a.get_inspections() > val_b.get_inspections();
        }
    );

    auto counter = 0;
    for (auto &monkey: monkeys)
    {
        std::cout << "Monkey " << counter << " inspected items " << monkey.get_inspections() << " times." << "\n";
        ++counter;
    }

    result = monkeys[0].get_inspections() * monkeys[1].get_inspections();
    return result;
}

#endif //DAY_11_SOLUTION_HPP
