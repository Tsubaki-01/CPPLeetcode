// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem54.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// 方向向量
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int di = 0;
        int dj = 1;
        int i = 0;
        int j = 0;
        int total = matrix.size() * matrix[0].size();
        vector<int> res(total, 0);
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (int t = 0; t < total; t++)
        {
            res[t] = matrix[i][j];
            visited[i][j] = 1;

            if (!(i + di >= 0 && i + di < matrix.size()
                && j + dj >= 0 && j + dj < matrix[0].size()
                && !visited[i + di][j + dj]))
            {
                swap(di, dj);
                dj = -dj;
            }

            i += di;
            j += dj;
        }

        return res;

    }
};
// @lc code=end

/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int di = 0;
        int dj = 1;
        int i = 0;
        int j = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n, 0);
        int cnt = 0;
        int loop = 0;

        while (cnt < m * n) {
            res[cnt] = matrix[i][j];
            if (i + di == loop && j + dj == loop) {
                loop++;
            }
            if (i + di >= m - loop || i + di < loop || j + dj < loop ||
                j + dj >= n - loop) {
                int t = dj;
                dj = -di;
                di = t;
            }
            i = i + di;
            j = j + dj;
            cnt++;
        }
        return res;
    }
};
 */