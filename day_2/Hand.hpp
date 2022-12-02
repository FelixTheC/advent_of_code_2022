//
// Created by felix on 02.12.22.
//

#ifndef DAY_2_HAND_HPP
#define DAY_2_HAND_HPP
#include <string_view>

class Hand
{
    int value;
    std::string_view name;

public:

    static const int LOST = 0;
    static const int DRAW = 3;
    static const int WIN = 6;

    Hand() : value(0), name("Null") {};
    Hand(int val, std::string_view name_) : value(val), name(name_) {}

    ~Hand() = default;

    virtual int play(Hand &rhs) {};
    virtual Hand* draw() {};
    virtual Hand* lose() {};
    virtual Hand* win() {};

    [[nodiscard]] std::string_view get_name() const
    {
        return name;
    }

    [[nodiscard]] int get_value() const
    {
        return value;
    }
};


#endif //DAY_2_HAND_HPP
