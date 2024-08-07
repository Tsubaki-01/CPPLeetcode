// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem718.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
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
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0) return 0;
        vector < vector<int >>dp(nums1.size(), vector<int>(nums2.size(), 0));
        int res = 0;
        if (nums1[0] == nums2[0])
            dp[0][0] = 1;
        else dp[0][0] = 0;

        for (int i = 1;i < dp[0].size();++i)
            if (nums1[0] == nums2[i])
                res = 1, dp[0][i] = 1;
        for (int i = 1;i < dp.size();++i)
            if (nums1[i] == nums2[0])
                res = 1, dp[i][0] = 1;

        for (int i = 1;i < dp.size();++i)
            for (int j = 1;j < dp[0].size();++j)
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }

        return res;

    }
};
// @lc code=end

