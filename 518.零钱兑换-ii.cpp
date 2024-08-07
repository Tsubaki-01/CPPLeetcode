// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem518.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
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
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));

        dp[0][0] = 1;
        for (int i = coins[0];i <= amount;++i)
            if (i % coins[0] == 0)
                dp[0][i] = 1;

        for (int i = 1;i < dp.size();++i)
            for (int j = 0;j < dp[0].size();++j)
                if (coins[i] > j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];

        return dp.back().back();

    }
};
// @lc code=end

