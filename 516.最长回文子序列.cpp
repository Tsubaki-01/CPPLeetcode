/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
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
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = dp.size();i >= 0;--i)
            for (int j = i;j < dp[0].size();++j)
                if (s[i] == s[j])
                    if (i == j)
                        dp[i][j] = 1;
                    else dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        return dp[0][s.size() - 1];
    }
};
// @lc code=end

