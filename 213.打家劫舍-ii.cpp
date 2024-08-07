/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
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
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0);
        int max1 = 0;
        int max2 = 0;

        // 不偷第一家
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3;i < dp.size();++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        max1 = dp.back();

        // 不偷最后一家
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2;i < dp.size() - 1;++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        max2 = dp[dp.size() - 2];

        return max(max1, max2);

    }
};
// @lc code=end

