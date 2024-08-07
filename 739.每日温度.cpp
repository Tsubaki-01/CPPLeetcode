// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem739.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> sta;
        vector<int> res(temperatures.size(), 0);
        if (temperatures.empty())
            return res;
        sta.push(0);
        for (int i = 1;i < temperatures.size();i++)
        {
            // if (temperatures[i] < temperatures[sta.top()])
            // {
            //     sta.push(i);
            //     continue;
            // }
            // else if (temperatures[i] == temperatures[sta.top()])
            // {
            //     sta.push(i);
            //     continue;
            // }
            while (!sta.empty() && temperatures[i] > temperatures[sta.top()])
            {
                int t = sta.top();
                sta.pop();
                res[t] = i - t;
            }
            sta.push(i);
        }
        return res;
    }
};
// @lc code=end

