/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
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
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.empty())
            return 0;

        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));

        for (int i = 0;i * 2 + 1 < dp[0].size();++i)
        {
            dp[0][i * 2] = 0;
            dp[0][i * 2 + 1] = 0 - prices[0];
        }

        for (int i = 1;i < dp.size();++i)
        {
            for (int j = 0;j + 2 < dp[0].size();j += 2)
            {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }

        return dp[dp.size() - 1][2 * k];

    }
};
// @lc code=end

