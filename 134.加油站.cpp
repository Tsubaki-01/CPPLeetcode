/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include<iostream>
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include<numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;
        vector<int> profit(gas.size(), 0);
        for (int i = 0;i < gas.size();i++)
            profit[i] = gas[i] - cost[i];
        int cnt = 0;
        int position = 0;
        for (int i = 0;i < gas.size();i++)
        {
            cnt += profit[i];
            if (cnt < 0)
            {
                position = i + 1;
                cnt = 0;
            }
        }
        return position;
    }
};
// @lc code=end

