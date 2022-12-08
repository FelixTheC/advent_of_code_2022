//
// Created by felix on 07.12.22.
//

#ifndef DAY_7_SOLUTION_HPP
#define DAY_7_SOLUTION_HPP

#include "PathObject.hpp"
#include "parse_command.hpp"


void solution_1(std::vector<std::string> &commands, std::shared_ptr<pathlib::PathObject> &root_object)
{
    bool list_files = false;
    int level = 0;
    auto base_root = root_object;

    for (auto &cmd: commands)
    {
        auto cmd_str = parse_cmd(cmd);
        if (cmd_str == "/")
        {
            continue;
        }
        else if (cmd_str.empty())
        {
            if (!list_files)
            {
                list_files = true;
            }
            else
            {
                auto path_object = std::make_shared<pathlib::PathObject>(parse_into_path_object(cmd));
                path_object->set_parent(root_object);
                root_object->files.emplace_back(path_object);
            }
        }
        else
        {
            list_files = false;
            auto sub_str = parse_cmd(cmd);
            if (sub_str == "..")
            {
                --level;
                auto parent_dir = root_object->get_parent();
                if (parent_dir)
                {
                    root_object = parent_dir;
                }
            }
            else
            {
                ++level;
                auto subdir = root_object->find_subdir(sub_str);
                if (subdir)
                {
                    root_object = subdir;
                }
            }
        }
    }
    root_object = base_root;
}

#endif //DAY_7_SOLUTION_HPP
