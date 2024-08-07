// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem115.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
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
    int numDistinct(string s, string t) {

        vector<vector<unsigned long>> dp(t.size(), vector<unsigned long>(s.size(), 0));

        dp[0][0] = (t[0] == s[0] ? 1 : 0);
        for (int i = 1;i < dp[0].size();++i)
            if (t[0] == s[i])
                dp[0][i] = dp[0][i - 1] + 1;
            else dp[0][i] = dp[0][i - 1];

        for (int i = 1;i < dp.size();++i)
            for (int j = i;j < dp[0].size();++j)
            {
                if (t[i] == s[j])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }

        return dp.back().back();
    }
};
// @lc code=end

