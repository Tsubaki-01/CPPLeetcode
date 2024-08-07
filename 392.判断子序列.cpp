/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
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
    bool isSubsequence(string s, string t) {
        if (s.size() == 0)
            return true;
        if (t.size() == 0)
            return false;

        vector<vector<bool>> dp(s.size(), vector<bool>(t.size(), false));

        dp[0][0] = (s[0] == t[0] ? true : false);
        for (int i = 1;i < dp[0].size();++i)
            if (s[0] == t[i]) dp[0][i] = true;
            else dp[0][i] = dp[0][i - 1];

        for (int i = 1;i < dp.size();++i)
            for (int j = i;j < dp[0].size();++j)
                if (s[i] == t[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = dp[i][j - 1];

        return dp.back().back();
    }
};
// @lc code=end

