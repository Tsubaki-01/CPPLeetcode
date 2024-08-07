/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大序列和
 */
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
// 贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int res = INT_MIN;
        int sum = 0;
        for (int i = 0;i < nums.size();++i)
        {
            sum += nums[i];
            res = max(res, sum);
            sum < 0 ? (sum = 0) : 1;
        }
        return res;
    }
};
// @lc code=end

// 动态规划

/* class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int res = dp[0];

        for (int i = 1;i < dp.size();++i)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(dp[i], res);
        }
        return res;
    }
}; */


// 前缀和