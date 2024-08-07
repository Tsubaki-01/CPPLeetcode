/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
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
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2 + 0.5;
        vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0));

        for (int i = stones[0];i < target + 1;i++)
            dp[0][i] = stones[0];

        for (int i = 1;i < dp.size();i++)
            for (int j = 0;j < dp[0].size();j++)
                if (j < stones[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);

        return abs(sum - 2 * dp[dp.size() - 1][dp[0].size() - 1]);
    }
};
// @lc code=end

