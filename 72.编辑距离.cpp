// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem72.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
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
        if (word1.size() == 0)
            return word2.size();
        if (word2.size() == 0)
            return word1.size();

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;

        for (int i = 1;i < dp.size();++i)
            for (int j = 1;j < dp[0].size();++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
            }

        return dp[word1.size()][word2.size()];

    }
};
// @lc code=end

