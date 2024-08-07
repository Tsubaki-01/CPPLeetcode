/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
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

        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, 0)));
        // i：第i天     j=0：第一次购票 j=1：第二次购票     k=0：不持有股票 k=1：持有股票
        dp[0][0][1] = 0 - prices[0];
        dp[0][0][0] = 0;
        dp[0][1][0] = 0;
        dp[0][1][1] = 0 - prices[0];

        for (int i = 1;i < dp.size();++i)
        {
            dp[i][0][1] = max(dp[i - 1][0][1], 0 - prices[i]);
            dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1] + prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
        }

        return dp[dp.size() - 1][1][0];
        // 只买卖一次跟不买卖的情况的答案包含在买卖两次里面
    }
};
// @lc code=end

