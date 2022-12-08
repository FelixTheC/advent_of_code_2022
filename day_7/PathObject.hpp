//
// Created by felix on 07.12.22.
//

#ifndef DAY_7_PATHOBJECT_HPP
#define DAY_7_PATHOBJECT_HPP

#include <memory>
#include <string>
#include <vector>

namespace pathlib
{

    class PathObject
    {
        const std::string name_;
        long int size_;
        bool is_file_;
        std::shared_ptr<PathObject> parent_dir_ {};

    public:
        PathObject() : name_(), size_(0), is_file_(false) {}
        explicit PathObject(const std::string& name) : name_(name), size_(0), is_file_(false) {};

        PathObject(const std::string &name,
                   long int file_size) : name_(name), size_(file_size), is_file_(true) {};

        PathObject(const PathObject& pathObject) : name_(pathObject.name()),
                                                   size_(pathObject.size()),
                                                   is_file_(pathObject.is_file()) {
            for (auto &val: pathObject.files)
            {
                this->files.emplace_back(val);
            }
            this->parent_dir_ = pathObject.get_parent();
        };

        ~PathObject()
        {
            files.clear();
        }

        std::vector<std::shared_ptr<PathObject>> files {};

        [[nodiscard]] std::shared_ptr<PathObject> get_parent() const;
        void set_parent(std::shared_ptr<PathObject>  &parent);

        [[nodiscard]] bool is_file() const;

        [[nodiscard]] std::string name() const;

        [[nodiscard]] long long int size() const;

        [[nodiscard]] std::shared_ptr<PathObject> find_subdir(const std::string &dir_name);

        [[nodiscard]] bool operator==(const PathObject &rhs) const;
        friend std::ostream& operator<<(std::ostream& ostream, const PathObject &pathObject);
    };

} // pathlib

#endif //DAY_7_PATHOBJECT_HPP
