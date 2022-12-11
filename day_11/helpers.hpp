//
// Created by felix on 11.12.22.
//

#ifndef DAY_11_HELPERS_HPP
#define DAY_11_HELPERS_HPP

template<typename T>
auto addition(T a, T b) -> T
{
    return a + b;
}

template<typename T>
auto multiply(T a, T b) -> T
{
    return a * b;
}

template<typename T>
auto monkeyTestFunc(T val, T divisor, T True, T False) -> T
{
    if (val % divisor == 0)
    {
        return True;
    }
    return False;
}

#endif //DAY_11_HELPERS_HPP
