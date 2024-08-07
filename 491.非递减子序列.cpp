/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */
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
    vector<vector<int>> result;
    vector<int> item;
    bool isUp(vector<int>& nums)
    {
        for (int i = 1;i < nums.size();i++)
            if (nums[i] < nums[i - 1])
                return false;
        return true;
    }
    void backtracking(vector<int>& nums, int index)
    {
        if (item.size() >= 2)
        {
            result.push_back(item);
        }
        if (index >= nums.size())
            return;

        int judge[201] = { 0 };
        for (int i = index;i < nums.size();i++)
        {
            if ((item.size() == 0 && judge[nums[i] + 100] == 0) ||
                (judge[nums[i] + 100] == 0 && nums[i] >= item.back()))
            {
                item.push_back(nums[i]);
                judge[nums[i] + 100] = 1;
            }
            else continue;
            backtracking(nums, i + 1); // 递归
            item.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end

