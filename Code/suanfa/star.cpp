#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

vector<pair<int, int>> MOVE = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

class Point
{
public:
    int row;
    int col;
    int f;
    Point *parent;
    pair<int, int> move;
    Point() : row(0), col(0), parent(nullptr), move({0, 0}) {}
    Point(int row, int col, Point *parent = nullptr, pair<int, int> move = {0, 0}) : row(row), col(col), parent(parent), move(move) {}
    int get_h(Point *end_point)
    {
        return 10 * abs(row - end_point->row) + 10 * abs(col - end_point->col);
    }
    // virtual function....暂不实现get_g
    void set_f(Point *end_point)
    {
        // 假设有get_g()方法
        f = get_h(end_point) + 10; // 暂时固定g为10
    }
};

class State
{
    vector<vector<int>> state;
    Point *current_point;
    Point *end_point;

public:
    State(vector<vector<int>> state, Point *current_point = new Point(-1, -1), Point *end_point = new Point(-1, -1)) : state(state), current_point(current_point), end_point(end_point) {}
};

// 函数头部需要修改各个参数的类型
void search_next_step(State *map, vector<Point *> &open_list, vector<Point *> &close_list, vector<Point *> &wrong_list)
{
    // 类似实现...
}

bool compare(Point *p1, Point *p2)
{
    return p1->f < p2->f;
}

void a_star(State *map, vector<Point *> &open_list, vector<Point *> &close_list, vector<Point *> &wrong_list)
{
    // 类似实现...
}

void showInfo(State *map, vector<Point *> &path)
{
    // 类似实现...
}

int main()
{

    vector<Point *> open_list;
    vector<Point *> close_list;
    vector<Point *> wrong_list;

    vector<vector<int>> state = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    Point *start_point = new Point(0, 0);
    Point *end_point = new Point(9, 9);

    State *Map = new State(state, new Point(0, 0), end_point);
    a_star(Map, open_list, close_list, wrong_list);

    vector<Point *> path = {start_point}; // lgd++
    path.insert(path.end(), close_list.begin(), close_list.end());

    cout << "Best Way: " << endl;
    showInfo(Map, path);

    return 0;
}
