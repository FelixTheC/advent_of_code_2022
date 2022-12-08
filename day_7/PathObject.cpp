//
// Created by felix on 07.12.22.
//

#include "PathObject.hpp"


namespace pathlib
{
    static int level = 0;


    bool PathObject::is_file() const
    {
        return is_file_;
    }

    std::string PathObject::name() const
    {
        return name_;
    }

    long long int PathObject::size() const
    {
        if (is_file_)
        {
            return size_;
        }
        else
        {
            int result = 0;
            std::for_each(files.begin(), files.end(),
                          [&result](auto &val){ result+=val->size(); });
            return result;
        }
    }

    bool PathObject::operator==(const PathObject &rhs) const
    {
        auto result = this->name_ == rhs.name_;
        result = result && this->is_file_ == rhs.is_file_;
        result = result && this->size() == rhs.size();
        result = result && this->files == rhs.files;
        return result;
    }

    std::shared_ptr<PathObject> PathObject::find_subdir(const std::string &dir_name)
    {
        for (auto &val: files)
        {
            if (val->name() == dir_name)
            {
                return val;
            }
        }
        return {};
    }

    std::shared_ptr<PathObject> PathObject::get_parent() const
    {
        return this->parent_dir_;
    }

    void PathObject::set_parent(std::shared_ptr<PathObject> &parent)
    {
        this->parent_dir_ = parent;
    }

    std::ostream &operator<<(std::ostream &ostream, const PathObject &pathObject)
    {
        std::string indentation {};
        for (int i = 0; i < level; ++i)
        {
            indentation += " ";
        }

        if(pathObject.is_file())
        {
            ostream << indentation << "FILE: " << pathObject.name() << " " << pathObject.size() << "\n";
        }
        else
        {
            ostream << indentation <<"DIR: " << pathObject.name() << " " << pathObject.size() << "\n";
        }

        if (!pathObject.files.empty())
        {
            ++level;
        }

        for (auto &val : pathObject.files)
        {
            ostream << indentation << "|-" << *val;
        }

        ostream << "\n";
        level = 0;

        return ostream;
    }


} // pathlib