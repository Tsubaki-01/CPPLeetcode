/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include<iostream>
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // 0不持有 1持有
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];
        for (int i = 1;i < dp.size();++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[dp.size() - 1][0];

    }
};
// @lc code=end
// 贪心
/* class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int sum = 0;
        for (int i = 0;i < prices.size() - 1;i++)
        {
            prices[i + 1] - prices[i] > 0 ? max += prices[i + 1] - prices[i] : 1;
        }
        return max;

    }
}; */