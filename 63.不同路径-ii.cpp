/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 1 && n == 1 && obstacleGrid[0][0] == 0) return 1;
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m,
            vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 1;i < m;i++)
        {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i - 1][0];
        }
        for (int j = 1;j < n;j++)
        {
            if (obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j - 1];
        }
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
            {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else dp[i][j] = 0;
            }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

