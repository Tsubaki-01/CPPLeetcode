#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};
vector<Point> directions{ {0,1},{1,0},{0,1},{1,0} };

int bfs(vector<vector<int>>& map, Point start, Point end)
{
    int rows = map.size();
    int cols = map[0].size();
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    q.push({ start.x,start.y,0 });
    visited[start.x][start.y] = true;

    while (!q.empty())
    {
        auto [x, y, dist] = q.front();
        q.pop();

        if (x == end.x && y == end.y)
        {
            return dist;
        }

        for (auto direc : directions)
        {
            int next_x = x + direc.x;
            int next_y = y + direc.y;

            if (next_x > 0 && next_x < rows &&
                next_y>0 && next_y < cols &&
                map[next_x][next_y] == 1)
            {
                q.push({ next_x,next_y ,dist + 1 });
                visited[next_x][next_y] = true;
            }

        }
    }
    return INT_MAX;
}

int res = INT_MAX;
void backtracking(int restMachine, Point cur, int dist, vector<Point> rest, vector<vector<int>>& map, Point end)
{
    if (restMachine == 0)
    {
        res = min(res, dist + bfs(map, cur, end));
        return;
    }

    for (int i = 0;i < rest.size();i++)
    {
        Point t = rest[i];
        rest.erase(rest.begin() + i);
        backtracking(restMachine - 1, t, dist + bfs(map, cur, t), rest, map, end); // 递归
        rest.push_back(t);
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> map(n, vector<int>(m));
    char c;
    Point T;
    Point start;
    Point end;
    vector<Point> machine;
    string s;
    for (int i = 0;i < n;i++)
    {
        cin >> s;
        for (int j = 0;j < m;j++)
        {
            c = s[j];
            if (c == 'S')
                map[i][j] = 10, start.x = i, start.y = j;
            else if (c == 'E')
                map[i][j] = 20, end.x = i, end.y = j;
            else if (c == '$')
                map[i][j] = 2;
            else if (c == 'T')
            {
                map[i][j] = 0; T.x = i; T.y = j;
            }
            else if (c == '#')
                map[i][j] = 0;
            else if (c == '.')
                map[i][j] = 1;
        }


    }


    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        {
            if (abs(i - T.x) + abs(j - T.y) <= k)
            {
                map[i][j] = 0;
            }
            if (map[i][j] == 2)
                machine.push_back({ i,j });
        }

    if (machine.size() < 5)
        cout << -1 << endl;

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }



    backtracking(5, start, 0, machine, map, end);

    cout << res << endl;


    return 0;
}

/*
5 5 1
#S$..
.$..$
$#.T.
$.$.E
#..$.
 */