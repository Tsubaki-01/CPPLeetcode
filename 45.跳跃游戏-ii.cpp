/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include<iostream>
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
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int range = 0;
        int curRange = 0;
        int step = 0;
        while (1)
        {
            for (int position = 0;position <= curRange;position++)
            {
                if (range < position + nums[position])
                {
                    range = position + nums[position];
                }
            }
            curRange = range;
            step++;
            if (range >= nums.size() - 1)
                return step;
        }
        return 0;
    }
};
// @lc code=end

