//
// Created by felix on 11.12.22.
//

#ifndef DAY_11_MONKEY_HPP
#define DAY_11_MONKEY_HPP

#include <functional>
#include <vector>
#include <deque>

using Number = unsigned long long;


class Monkey
{
    std::deque<Number> item_worry_levels_ {};
    std::function<Number (Number) > operation_ {};
    std::function<Number (Number)> test_ {};

    unsigned int inspections_ = 0;

public:
    Monkey() = default;
    Monkey(std::deque<Number> &&starting_items,
           std::function<Number (Number) > operation,
           std::function<Number (Number) > test) : item_worry_levels_(starting_items)
    {
        operation_ = std::move(operation);
        test_ = std::move(test);
    }

    ~Monkey()
    {
        item_worry_levels_.clear();
    }

    void round(std::vector<Monkey> &monkeys, float worry_reduce = 3.0);
    void catch_item(Number &item);

    [[nodiscard]] unsigned int get_inspections() const
    {
        return inspections_;
    }
};


#endif //DAY_11_MONKEY_HPP
