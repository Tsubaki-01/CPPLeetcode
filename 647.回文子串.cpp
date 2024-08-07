/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
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
    int countSubstrings(string s) {
        if (s.size() == 0)
            return 0;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int cnt = 0;
        for (int i = 0;i < dp.size();++i)
        {
            dp[i][i] = true;
            cnt++;
        }

        for (int i = dp.size();i >= 0;--i)
            for (int j = i + 1;j < dp[0].size();++j)
            {
                if (s[i] == s[j])
                    if (j == i + 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                if (dp[i][j])
                    cnt++;
            }

        return cnt;
    }
};
// @lc code=end

// 双指针  从前往后遍历选取回文串的中心点
/* class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size()); // 以i为中心
            result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
        }
        return result;
    }
    int extend(const string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
}; */