#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

std::vector<std::deque<char>> crates {
    std::deque<char>({'N', 'F', 'C', 'W', 'T', 'D', 'L', 'B'}),
    std::deque<char>({'L', 'B', 'N'}),
    std::deque<char>({'V', 'L', 'T', 'H', 'C', 'J'}),
    std::deque<char>({'W', 'J', 'P', 'S'}),
    std::deque<char>({'R', 'L', 'T', 'F', 'C', 'S', 'Z'}),
    std::deque<char>({'Z', 'N', 'H', 'B', 'G', 'D', 'W'}),
    std::deque<char>({'N', 'C', 'G', 'V', 'P', 'S', 'M', 'F'}),
    std::deque<char>({'Z', 'C', 'V', 'F', 'J', 'R', 'Q', 'W'}),
    std::deque<char>({'H', 'L', 'M', 'P', 'R'}),
};

// test crates
//std::vector<std::deque<char>> crates {std::deque<char>({'N', 'Z'}),
//                                      std::deque<char>({'D', 'C', 'M'}),
//                                      std::deque<char>({'P'}),
//};

struct MoveInstruction
{
    int size;
    int from;
    int to;

    explicit MoveInstruction(int s, int f, int t) : size(s), from(f - 1), to(t - 1) {}

    void move_crate(std::vector<std::deque<char>> &crates_) const
    {
        for (int idx = 0; idx < size; ++idx)
        {
            auto val = crates_[from].front();
            crates_[from].pop_front();
            crates_[to].push_front(val);
        }
    }

    void move_crate_ordered(std::vector<std::deque<char>> &crates_) const
    {
        if (size == 1)
        {
            move_crate(crates_);
        }
        else
        {
            std::deque<char> tmp {};

            for (int idx = 0; idx < size; ++idx)
            {

                auto value = crates_[from].front();
                crates_[from].pop_front();

                tmp.push_front(value);
            }

            for(int idx = 0; idx < size; ++idx)
            {
                auto chr = tmp.front();
                tmp.pop_front();
                crates_[to].push_front(chr);
            }
        }
    }
};

[[nodiscard]] std::vector<MoveInstruction> file_reader(const std::string &file_name)
{
    std::ifstream ifstream;
    ifstream.open(file_name);

    std::vector<MoveInstruction> lines{};

    if (ifstream.is_open())
    {
        while (!ifstream.eof())
        {
            std::string line;
            std::getline(ifstream, line);

            auto from_pos = line.find("from");
            auto to_pos = line.find("to");

            auto size_str = std::stoi(line.substr(5, 2));
            auto from_str = std::stoi(line.substr(from_pos + 5, to_pos - (from_pos + 5)));
            auto to_str = std::stoi(line.substr(to_pos + 3, line.size() - (to_pos + 3)));

            lines.emplace_back(MoveInstruction(size_str, from_str, to_str));
        }
    }

    ifstream.close();

    return lines;
}

int main()
{
//    test moves
//    std::vector<MoveInstruction> moves {MoveInstruction(1, 2, 1),
//                                        MoveInstruction(3, 1, 3),
//                                        MoveInstruction(2, 2, 1),
//                                        MoveInstruction(1, 1, 2)};

    const std::string file = "/home/felix/CLionProjects/advent_of_code_2022/day_5/input_move_instr.txt";
    auto moves = file_reader(file);

    for (auto move : moves)
    {
        move.move_crate_ordered(crates);
    }

    std::string result {};

    for (const auto& val: crates)
    {
        auto tmp = val.front();
        result.push_back(tmp);
    }

    std::cout << "Result: " << result << "\n";

    return 0;
}
