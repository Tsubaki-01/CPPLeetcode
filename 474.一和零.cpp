// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem474.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
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
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.empty())
            return 0;
        // 可以不排序
        // sort(strs.begin(), strs.end(), [](string& a, string& b)
        //     {return a.length() < b.length();});

        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        // 可以不判断
        // if (count(strs[0].begin(), strs[0].end(), '0') > m
        //     || count(strs[0].begin(), strs[0].end(), '1') > n)
        //     return 0;

        for (int i = count(strs[0].begin(), strs[0].end(), '0');i < dp[0].size();++i)
            for (int j = count(strs[0].begin(), strs[0].end(), '1');j < dp[0][0].size();++j)
                dp[0][i][j] = 1;

        for (int i = 1;i < dp.size();++i)
            for (int j = 0;j < dp[0].size();++j)
                for (int k = 0;k < dp[0][0].size();++k)
                {
                    int cnt_0 = count(strs[i].begin(), strs[i].end(), '0');
                    int cnt_1 = count(strs[i].begin(), strs[i].end(), '1');

                    if (cnt_0 <= j
                        && cnt_1 <= k)
                        dp[i][j][k] = max(dp[i - 1][j][k],
                            dp[i - 1][j - cnt_0][k - cnt_1] + 1);
                    else dp[i][j][k] = dp[i - 1][j][k];
                }


        return dp.back().back().back();
    }
};
// @lc code=end

