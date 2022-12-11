//
// Created by felix on 11.12.22.
//

#ifndef DAY_11_PARSE_INPUT_HPP
#define DAY_11_PARSE_INPUT_HPP

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>
#include <functional>
#include <deque>

#include "helpers.hpp"
#include "Monkey.hpp"

struct TestFunctionConstr
{
    unsigned short divisor;
    unsigned short true_val;
    unsigned short false_val;

    std::function< Number (Number) > test_function()
    {
        return std::bind(monkeyTestFunc<Number>, std::placeholders::_1, divisor, true_val, false_val);
    }
};

struct MonkeyConstruction
{
    std::deque<Number> item_worry_levels {};
    std::function<Number (Number) > operation {};
    TestFunctionConstr testFunctionConstr;

    Monkey generate_monkey()
    {
        return {std::move(item_worry_levels),
                operation,
                testFunctionConstr.test_function()};
    }
};

namespace puzzle {

    const std::string STARTING_ITEMS_STR = "  Starting items: ";
    const size_t STARTING_ITEMS_SIZE = STARTING_ITEMS_STR.size();

    const std::string TEST_STR = "  Test: divisible by ";
    const size_t TEST_STR_START = TEST_STR.size();

    const std::string TRUE_THROW_STR = "    If true: throw to monkey ";
    const size_t TRUE_THROW_START = TRUE_THROW_STR.size();

    const std::string FALSE_THROW_STR = "    If false: throw to monkey ";
    const size_t FALSE_THROW_START = FALSE_THROW_STR.size();

    [[nodiscard]] std::deque<Number> parse_starting_items(const std::string &&line)
    {
        std::deque<Number> result {};

        std::string values_str = line.substr(STARTING_ITEMS_SIZE, line.size() - STARTING_ITEMS_SIZE);

        std::string val;
        std::stringstream stringstream(values_str);

        while(std::getline(stringstream, val, ','))
        {
            auto tmp = std::stoi(val);
            result.emplace_back(tmp);
        }

        return result;
    }

    [[nodiscard]] std::function<Number (Number)> parse_operation(const std::string &&line)
    {
        size_t start_pos {};
        auto addition = false;
        std::function<Number (Number)> operation;

        if (line.find('+') != std::string::npos)
        {
            start_pos = line.find('+');
            addition = true;
        }
        else
        {
            start_pos = line.find('*');
        }

        auto tmp = line.substr(start_pos + 1, line.size() - start_pos);

        if (tmp == "old" || tmp == " old")
        {
            if (addition)
            {
                operation = std::bind(::addition<Number>, std::placeholders::_1, std::placeholders::_1);
            }
            else
            {

                operation = std::bind(::multiply<Number>, std::placeholders::_1, std::placeholders::_1);
            }
        }
        else
        {
            auto value = std::stoi(tmp);

            if (addition)
            {
                operation = std::bind(::addition<Number>, std::placeholders::_1, value);
            }
            else
            {

                operation = std::bind(::multiply<Number>, std::placeholders::_1, value);
            }
        }

        return operation;
    }

    [[nodiscard]] std::vector<Monkey> parse_input(const std::string &filename)
    {
        std::ifstream ifstream;
        ifstream.open(filename);

        std::vector<Monkey> monkeys {};

        if(ifstream.is_open())
        {
            MonkeyConstruction monkeyConstruction {};
            TestFunctionConstr testFunctionConstr {};

            while (!ifstream.eof())
            {
                std::string line;
                std::getline(ifstream, line);

                if (line.find("Starting") != std::string::npos)
                {
                    auto val = parse_starting_items(std::move(line));
                    monkeyConstruction.item_worry_levels = std::move(val);
                }
                else if (line.find("Operation") != std::string::npos)
                {
                    auto val = parse_operation(std::move(line));
                    monkeyConstruction.operation = std::move(val);
                }
                else if (line.empty())
                {
                    monkeyConstruction.testFunctionConstr = testFunctionConstr;
                    monkeys.emplace_back(monkeyConstruction.generate_monkey());

                    monkeyConstruction = {};
                    testFunctionConstr = {};
                }
                else if (line.find("true") != std::string::npos)
                {
                    auto val = line.substr(TRUE_THROW_START, line.size() - TRUE_THROW_START);
                    testFunctionConstr.true_val = std::stoi(val);
                }
                else if (line.find("false") != std::string::npos)
                {
                    auto val = line.substr(FALSE_THROW_START, line.size() - FALSE_THROW_START);
                    testFunctionConstr.false_val = std::stoi(val);
                }
                else if (line.find("Monkey") != std::string::npos)
                {
                    continue;
                }
                else
                {
                    auto val = line.substr(TEST_STR_START, line.size() - TEST_STR_START);
                    testFunctionConstr.divisor = std::stoi(val);
                }
            }

            monkeyConstruction.testFunctionConstr = testFunctionConstr;
            monkeys.emplace_back(monkeyConstruction.generate_monkey());
        }

        ifstream.close();

        return monkeys;
    }
};
#endif //DAY_11_PARSE_INPUT_HPP
