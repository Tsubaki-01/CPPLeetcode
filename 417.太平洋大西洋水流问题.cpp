// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem417.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& capacity, int x, int y)
    {
        if (!capacity[x][y])
        {
            capacity[x][y] = true;

            int direction[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };

            queue<pair<int, int >> que;
            que.push({ x,y });

            while (!que.empty())
            {
                int cur_x = que.front().first;
                int cur_y = que.front().second;
                que.pop();

                for (int i = 0;i < 4;i++)
                {
                    int next_x = cur_x + direction[i][0];
                    int next_y = cur_y + direction[i][1];
                    if (next_x < 0 || next_x >= heights.size() || next_y < 0 || next_y >= heights[0].size() || capacity[next_x][next_y])
                    {
                        continue;
                    }
                    if (heights[next_x][next_y] >= heights[cur_x][cur_y])
                    {
                        que.push({ next_x,next_y });
                        capacity[next_x][next_y] = true;
                    }
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;
        if (heights.empty())
            return res;

        vector<vector<bool>> Pac(m, vector<bool >(n, false));
        vector<vector<bool>> Atl(m, vector<bool >(n, false));

        for (int i = 0;i < m;i++)
        {
            bfs(heights, Pac, i, 0);
            bfs(heights, Atl, i, n - 1);
        }
        for (int j = 0;j < n;j++)
        {
            bfs(heights, Pac, 0, j);
            bfs(heights, Atl, m - 1, j);
        }

        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
                if (Pac[i][j] && Atl[i][j])
                    res.push_back({ i,j });

        return res;

    }


};
// @lc code=end

