/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

 // @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // 0不持有 1持有
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];
        for (int i = 1;i < dp.size();++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[dp.size() - 1][0];
    }
};
// @lc code=end

