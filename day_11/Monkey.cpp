//
// Created by felix on 11.12.22.
//

#include <iostream>
#include <cmath>
#include "Monkey.hpp"

void Monkey::round(std::vector<Monkey> &monkeys, float worry_reduce)
{
    inspections_ += item_worry_levels_.size();

    while (!item_worry_levels_.empty())
    {
        auto item = item_worry_levels_.front();

        Number worry_level = std::floor(operation_(item) / worry_reduce);
        auto result = test_(worry_level);

        monkeys[result].catch_item(worry_level);

        item_worry_levels_.pop_front();
    }
}

void Monkey::catch_item(Number &item)
{
    item_worry_levels_.push_back(item);
}
