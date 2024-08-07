// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem827.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <list>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:

    vector<vector<int>> xyToIndex;
    unordered_map<int, int> indexToSquare;


    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& index)
    {
        if (!visited[x][y])
        {

            int direction[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };
            int t = 0;
            index++;

            queue<pair<int, int>> que;
            que.push({ x,y });
            visited[x][y] = true;
            xyToIndex[x][y] = index;
            t++;

            while (!que.empty())
            {
                int cur_x = que.front().first;
                int cur_y = que.front().second;
                que.pop();

                for (int i = 0;i < 4;i++)
                {
                    int next_x = cur_x + direction[i][0];
                    int next_y = cur_y + direction[i][1];
                    if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || visited[next_x][next_y] || grid[next_x][next_y] == 0)
                        continue;

                    que.push({ next_x,next_y });
                    visited[next_x][next_y] = true;
                    xyToIndex[next_x][next_y] = index;
                    t++;
                }
            }
            indexToSquare[index] = t;
        }
    }



    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        xyToIndex.resize(m, vector<int>(n, 0));
        int index = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
            {
                if (grid[i][j] == 1)
                {
                    bfs(grid, visited, i, j, index);
                }
            }

        int res;
        if (indexToSquare.empty())
            res = 0;
        else
            res = max_element(indexToSquare.begin(), indexToSquare.end(), [](pair<char, int> left, pair<char, int> right) { return left.second < right.second; })->second;

        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
            {
                if (grid[i][j] == 0)
                {
                    int direction[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };
                    int t = 1;
                    unordered_set<int> set;
                    for (int k = 0;k < 4;k++)
                    {
                        int next_x = i + direction[k][0];
                        int next_y = j + direction[k][1];
                        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || grid[next_x][next_y] == 0)
                            continue;
                        else {
                            set.emplace(xyToIndex[next_x][next_y]);
                        }
                    }
                    for (auto index : set)
                    {
                        t += indexToSquare[index];
                    }
                    res = max(res, t);
                }
            }
        return res;
    }
};
// @lc code=end

