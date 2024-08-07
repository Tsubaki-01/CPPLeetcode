/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
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
    int minDistance(string word1, string word2) {
        if (word1.size() == 0 || word2.size() == 0) return 0;
        vector < vector<int >>dp(word1.size(), vector<int>(word2.size(), 0));
        if (word1[0] == word2[0])
            dp[0][0] = 1;
        else dp[0][0] = 0;

        for (int i = 1;i < dp[0].size();++i)
            if (word1[0] == word2[i])
                dp[0][i] = 1;
            else dp[0][i] = dp[0][i - 1];
        for (int i = 1;i < dp.size();++i)
            if (word1[i] == word2[0])
                dp[i][0] = 1;
            else dp[i][0] = dp[i - 1][0];

        for (int i = 1;i < dp.size();++i)
            for (int j = 1;j < dp[0].size();++j)
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

        return word1.size() + word2.size() - 2 * dp.back().back();
    }
};
// @lc code=end

