// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem96.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
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

// 1~n-1 和 2~n 的树，结构是一样的

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if (n <= 2)
            return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3;i < n + 1;i++)
        {

            for (int left = 0;left <= i - 1;left++)
            {
                int right = i - 1 - left;
                dp[i] += dp[left] * dp[right];
            }

            /* int index = 1;
            for (;index < i / 2 + 1;index++)
            {
                dp[i] += 2 * (dp[index - 1] * dp[i - index]);
            }
            if (i % 2 == 1) dp[i] += dp[index - 1] * dp[index - 1]; */
        }

        return dp[n];

    }
};
// @lc code=end

