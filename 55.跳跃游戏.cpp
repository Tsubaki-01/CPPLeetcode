/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
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
    bool canJump(vector<int>& nums) {
        int range = 0;
        int i = 0;
        while (i <= range)
        {
            if (range < i + nums[i])  range = i + nums[i];
            i++;
            if (range >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end

