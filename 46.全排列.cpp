/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
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
    void backtracking(vector<int>& nums, vector<int>& used)
    {
        if (item.size() == nums.size())
        {
            result.push_back(item);
            return;
        }

        for (int i = 0;i < nums.size();i++)
        {
            if (used[i] == 0)
            {
                item.push_back(nums[i]);
                used[i] = 1;
            }
            else continue;
            backtracking(nums, used); // 递归
            item.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end

