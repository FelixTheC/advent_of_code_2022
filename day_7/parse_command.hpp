//
// Created by felix on 07.12.22.
//

#ifndef DAY_7_PARSE_COMMAND_HPP
#define DAY_7_PARSE_COMMAND_HPP

#include <string>
#include "PathObject.hpp"

const std::string CD_CMD = "$ cd ";
const std::string DIR_INFO = "dir ";

using pathlib::PathObject;

[[nodiscard]] std::string parse_cmd(const std::string &cmd)
{
    std::string result {};

    if (cmd.find("cd") != std::string::npos)
    {
        result = cmd.substr(CD_CMD.size(), cmd.size() - CD_CMD.size());
    }

    return result;
}

[[nodiscard]] PathObject parse_into_path_object(const std::string &cmd)
{
    if (cmd.find("dir") != std::string::npos)
    {
        auto dir_name = cmd.substr(DIR_INFO.size(), cmd.size() - DIR_INFO.size());
        return PathObject{dir_name};
    }
    else
    {
        auto whitespace = cmd.find(" ");
        std::string size_str = cmd.substr(0, whitespace);
        std::string name = cmd.substr(whitespace + 1, cmd.size() - whitespace);

        long size = std::stoi(size_str);
        return PathObject{name, size};
    }

}

#endif //DAY_7_PARSE_COMMAND_HPP
