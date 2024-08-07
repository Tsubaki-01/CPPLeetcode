#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <array>
#include <random>
#include <unordered_set>
#include <algorithm>

class Node
{
public:
    std::vector<std::vector<int>> state;
    Node *parent;
    std::string move;
    int g;
    int h;
    int n;

    Node(std::vector<std::vector<int>> state_, Node *parent_ = nullptr, std::string move_ = "")
        : state(state_), parent(parent_), move(move_)
    {
        g = 0;
        h = heuristic();
        n = notformalsit();
    }

    bool operator<(const Node &other) const
    {
        return (g + n * h) < (other.g + n * other.h);
    }

    int heuristic()
    {
        int distance = 0;
        std::vector<int> final_state_1d = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
        std::array<std::array<int, 4>, 4> final_state;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                final_state[i][j] = final_state_1d[i * 4 + j];
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (state[i][j] == final_state[i][j] || state[i][j] == 0)
                {
                    continue;
                }
                else
                {
                    int final_x = (state[i][j] - 1) / 4;
                    int final_y = (state[i][j] - 1) % 4;
                    distance += std::abs(i - final_x) + std::abs(j - final_y);
                }
            }
        }
        return distance;
    }

    int notformalsit()
    {
        int count = 1;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (state[i][j] != 4 * i + j)
                {
                    count += 1;
                }
            }
        }
        return count;
    }
};

int count_inversions(std::vector<int> &sequence)
{
    int inversions = 0;
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        for (size_t j = i + 1; j < sequence.size(); ++j)
        {
            if (sequence[i] > sequence[j] && sequence[j] != 0)
            {
                inversions += 1;
            }
        }
    }
    return inversions;
}

std::vector<std::vector<int>> create_initial_state()
{
    std::vector<int> sequence = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(sequence.begin(), sequence.end(), g);

    while (count_inversions(sequence) % 2 != 0)
    {
        std::shuffle(sequence.begin(), sequence.end(), g);
    }
    // std::cout << count_inversions(sequence) << std::endl;
    /*
    for (int k = 0; k < sequence.size(); k++)
        std::cout << sequence[k] << std::endl;
 */
    sequence.push_back(0);
    std::vector<std::vector<int>> initial_state(4, std::vector<int>(4));
    int k = 0;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            // std::cout << sequence[k] << ' ';
            initial_state[i][j] = sequence[k++];
        }
    }

    return initial_state;
}

std::vector<Node> get_neighbors(Node &node)
{
    std::vector<Node> neighbors;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int i_0 = -1, j_0 = -1;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (node.state[i][j] == 0)
            {
                i_0 = i;
                j_0 = j;
            }
        }
    }

    for (auto &move : directions)
    {
        int next_i = i_0 + move.first;
        int next_j = j_0 + move.second;
        if (0 <= next_i && next_i < 4 && 0 <= next_j && next_j < 4)
        {
            std::vector<std::vector<int>> new_state = node.state;
            std::swap(new_state[i_0][j_0], new_state[next_i][next_j]);
            neighbors.push_back(Node(new_state, &node, std::to_string(node.state[next_i][next_j])));
        }
    }
    return neighbors;
}

std::vector<std::vector<std::vector<int>>> a_star(const std::vector<std::vector<int>> &initial_state,
                                                  const std::array<std::array<int, 4>, 4> &final_state)
{
    std::priority_queue<Node> open_list;
    std::vector<std::vector<std::vector<int>>> closed_set;
    Node initial_node(initial_state);
    open_list.push(initial_node);
    int node_num = 0;

    while (!open_list.empty())
    {
        Node current_node = open_list.top();
        open_list.pop();
        node_num++;

        std::vector<std::vector<int>> current_state = current_node.state;
        bool equal = true;

        for (int i = 0; i < 4 && equal; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (current_state[i][j] != final_state[i][j])
                {
                    equal = false;
                    break;
                }
            }
        }

        if (equal)
        {
            std::vector<std::vector<std::vector<int>>> path;
            while (current_node.parent)
            {
                if (!current_node.move.empty())
                {
                    path.push_back(current_node.state);
                }
                current_node = *(current_node.parent);
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        closed_set.push_back(current_node.state);

        for (Node &neighbor : get_neighbors(current_node))
        {
            bool found_in_closed_set = false;
            for (const auto &state : closed_set)
            {
                bool equal_states = true;
                for (int i = 0; i < 4 && equal_states; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (neighbor.state[i][j] != state[i][j])
                        {
                            equal_states = false;
                            break;
                        }
                    }
                }
                if (equal_states)
                {
                    found_in_closed_set = true;
                    break;
                }
            }
            if (!found_in_closed_set)
            {
                neighbor.g = current_node.g + 1;
                open_list.push(neighbor);
            }
        }
    }
    return {};
}

int main()
{
    std::vector<std::vector<int>> initial_state = create_initial_state();
    std::cout << "初始状态" << std::endl;

    for (const auto &row : initial_state)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    std::array<std::array<int, 4>, 4> final_state = {{{1, 2, 3, 4},
                                                      {5, 6, 7, 8},
                                                      {9, 10, 11, 12},
                                                      {13, 14, 15, 0}}};

    /*    for (const auto &row : final_state)
       {
           for (int val : row)
           {
               std::cout << val << " ";
           }
           std::cout << "\n";
       }
    */
    std::vector<std::vector<std::vector<int>>> solution = a_star(initial_state, final_state);
    int step = 1;
    for (const auto &state : solution)
    {
        std::cout << "第" << step++ << "步" << std::endl;
        for (const auto &row : state)
        {
            for (int val : row)
            {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "累计步数 " << solution.size() << std::endl;

    return 0;
}
