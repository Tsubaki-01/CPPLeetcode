/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
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
    int longestCommonSubsequence(string text1, string text2) {

        if (text1.size() == 0 || text2.size() == 0) return 0;
        vector < vector<int >>dp(text1.size(), vector<int>(text2.size(), 0));
        if (text1[0] == text2[0])
            dp[0][0] = 1;
        else dp[0][0] = 0;

        for (int i = 1;i < dp[0].size();++i)
            if (text1[0] == text2[i])
                dp[0][i] = 1;
            else dp[0][i] = dp[0][i - 1];
        for (int i = 1;i < dp.size();++i)
            if (text1[i] == text2[0])
                dp[i][0] = 1;
            else dp[i][0] = dp[i - 1][0];

        for (int i = 1;i < dp.size();++i)
            for (int j = 1;j < dp[0].size();++j)
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

        return dp.back().back();
    }
};
// @lc code=end

