// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem343.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
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
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3;i <= n;i++)
        {
            for (int j = 1;j < i;j++)
            {
                dp[i] = max(max(dp[i], dp[i - j] * j), j * (i - j));
            }
        }
        return dp[n];
    }
};
// @lc code=end

