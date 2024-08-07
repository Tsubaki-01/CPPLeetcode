/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
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
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, INT_MAX - 1));

        dp[0][0] = 0;
        if (coins[0] <= amount)
            for (int i = coins[0];i < dp[0].size();++i)
                if (i % coins[0] == 0)
                    dp[0][i] = i / coins[0];

        for (int i = 1;i < dp.size();++i)
            for (int j = 0;j < dp[0].size();++j)
                if (coins[i] <= j)
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
                else dp[i][j] = dp[i - 1][j];


        if (dp.back().back() != INT_MAX - 1)
            return dp.back().back();
        else return -1;
    }
};
// @lc code=end

