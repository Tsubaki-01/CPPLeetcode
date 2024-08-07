// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem42.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
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
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;

        int res = 0;
        stack<int> sta;
        sta.push(0);

        for (int i = 1;i < height.size();i++)
        {
            if (height[i] < height[sta.top()])
                sta.push(i);
            else if (height[i] == height[sta.top()])
            {
                sta.pop();
                sta.push(i);
            }
            else {
                while (!sta.empty() && height[i] >= height[sta.top()])
                {
                    int t = sta.top();
                    sta.pop();
                    if (!sta.empty())
                        res += (min(height[i], height[sta.top()]) - height[t]) * (i - sta.top() - 1);
                }

                sta.push(i);
            }
        }

        return res;

    }
};
// @lc code=end

