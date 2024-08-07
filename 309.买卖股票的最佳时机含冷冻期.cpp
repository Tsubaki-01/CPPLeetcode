/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
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
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        // 0不持有却能购入 1持有 2冷却 3今日售出,不持有却不能购入
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];
        dp[0][2] = 0;
        dp[0][3] = 0;
        for (int i = 1;i < dp.size();++i)
        {
            dp[i][0] = max(dp[i - 1][3], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][3];
            dp[i][3] = dp[i - 1][1] + prices[i];
        }

        return max(dp[dp.size() - 1][0], max(dp[dp.size() - 1][3], dp[dp.size() - 1][2]));
    }
};
// @lc code=end

