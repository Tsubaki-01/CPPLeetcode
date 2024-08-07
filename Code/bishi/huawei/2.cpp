#include <bits/stdc++.h>
using namespace std;

typedef struct p
{
    int i;
    int j;
    int status; // 0起点 -1终点 -2阻塞点 -3检查点

    p(int _i, int _j, int _status) :i(_i), j(_j), status(_status) {};
}point;

void add_reachable_point(point p, priority_queue<point, int>& reachable, vector<vector<point>> map, vector<vector<int>> flag)
{
    if (p.i == 0 && p.j == 0)
    {
        if (map[p.i][p.j + 1].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace(map[p.i][p.j + 1]);
        if (map[p.i + 1][p.j].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i + 1][p.j]);
    }
    else if (p.i == 0)
    {
        if (map[p.i][p.j + 1].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i][p.j + 1]);
        if (map[p.i + 1][p.j].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i + 1][p.j]);
        if (map[p.i][p.j - 1].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i][p.j - 1]);
    }
    else if (p.j == 0)
    {
        if (map[p.i][p.j + 1].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i][p.j + 1]);
        if (map[p.i + 1][p.j].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i + 1][p.j]);
        if (map[p.i - 1][p.j].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i - 1][p.j]);
    }
    else {
        if (map[p.i][p.j + 1].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i][p.j + 1]);
        if (map[p.i + 1][p.j].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i + 1][p.j]);
        if (map[p.i - 1][p.j].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i - 1][p.j]);
        if (map[p.i][p.j - 1].status != -2 && flag[p.i][p.j + 1] == 0)
            reachable.emplace_back(map[p.i][p.j - 1]);
    }


}

int fun(point start, point end, vector<vector<point>> map, vector<vector<int>>& flag)
{
    priority_queue<pair<point, int>, vector<pair<point, int>>, less<int>> reachable;
    map < point,
        add_reachable_point(start, reachable, map, flag);
    flag[start.i][start.j] = 1;
    while (!reachable.empty())
    {

    }


}



int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<point>> map(n, vector<point>(m));
    vector<vector<int>> flag(n, vector<int>(m, 0));
    int cnt = 0;
    char c;
    while (cin >> c)
        if (c == 'S')
            map[cnt / m][cnt % n] = point(cnt / m, cnt % n, 0);
        else if (c == 'E')
            map[cnt / m][cnt % n] = point(cnt / m, cnt % n, -1);
        else if (c == 'B')
            map[cnt / m][cnt % n] = point(cnt / m, cnt % n, -2);
        else if (c == 'C')
            map[cnt / m][cnt % n] = point(cnt / m, cnt % n, -3);
        else map[cnt / m][cnt % n] = point(cnt / m, cnt % n, c - '0');




    return 0;
}