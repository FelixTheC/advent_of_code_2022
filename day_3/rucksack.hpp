#include <algorithm>
#include <map>
#include <iostream>
#include <string_view>
#include <set>
#include <tuple>


[[nodiscard]] std::pair<std::string, std::string> get_rucksack_compartment(const std::string_view &val)
{
    auto result = std::pair<std::string, std::string>(val.substr(0, val.size() / 2),
                                                                val.substr(val.size() / 2, val.size()));
    return result;
}

[[nodiscard]] std::string find_sharing_compartment(std::pair<std::string , std::string> &compartments)
{
    auto first = std::get<0>(compartments);
    auto second = std::get<1>(compartments);

    std::string tmp_result {};

    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    std::set_intersection(first.begin(), first.end(),
                          second.begin(), second.end(),
                          std::back_inserter(tmp_result));

    std::set<char> result {};
    result.insert(tmp_result.begin(), tmp_result.end());

    if (!result.empty())
    {
        std::string tmp {};
        tmp.push_back(*result.begin());
        return tmp;
    }

    return tmp_result;
}

[[nodiscard]] std::string find_sharing_compartment(const std::string &a, const std::string &b, const std::string &c)
{
    std::set<char> result {};
    std::for_each(a.begin(), a.end(), [&result, &b, &c](auto &val)
    {
        if (std::find(b.begin(), b.end(), val) != std::end(b) && std::find(c.begin(), c.end(), val) != std::end(c))
        {
            result.insert(val);
        }
    });

    if (!result.empty())
    {
        std::string tmp {};
        tmp.push_back(*result.begin());
        return tmp;
    }

    return "";
}


std::map<std::string, int> PRIORITY = {
        {"a", 1},
        {"b", 2},
        {"c", 3},
        {"d", 4},
        {"e", 5},
        {"f", 6},
        {"g", 7},
        {"h", 8},
        {"i", 9},
        {"j", 10},
        {"k", 11},
        {"l", 12},
        {"m", 13},
        {"n", 14},
        {"o", 15},
        {"p", 16},
        {"q", 17},
        {"r", 18},
        {"s", 19},
        {"t", 20},
        {"u", 21},
        {"v", 22},
        {"w", 23},
        {"x", 24},
        {"y", 25},
        {"z", 26},
        {"A", 27},
        {"B", 28},
        {"C", 29},
        {"D", 30},
        {"E", 31},
        {"F", 32},
        {"G", 33},
        {"H", 34},
        {"I", 35},
        {"J", 36},
        {"K", 37},
        {"L", 38},
        {"M", 39},
        {"N", 40},
        {"O", 41},
        {"P", 42},
        {"Q", 43},
        {"R", 44},
        {"S", 45},
        {"T", 46},
        {"U", 47},
        {"V", 48},
        {"W", 49},
        {"X", 50},
        {"Y", 51},
        {"Z", 52},
};
