/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
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
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / 2;
        if (target * 2 != sum)
            return false;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));

        for (int i = nums[0];i <= target;i++)
            dp[0][i] = nums[0];

        for (int i = 1;i < nums.size();i++)
            for (int j = 0;j <= target;j++)
                if (j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);

        if (dp[nums.size() - 1][target] == target)
            return true;
        return false;

    }
};
// @lc code=end

