/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
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

// 二维爬楼梯

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target + 1, 0);
        dp[0] = 1;

        for (int j = 0;j < dp.size();++j)
            for (int i = 0;i < nums.size();++i)
                if (nums[i] <= j)
                    dp[j] += dp[j - nums[i]];

        return dp.back();
    }
};
// @lc code=end

