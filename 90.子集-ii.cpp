/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
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

    void backtracking(vector<int>& nums, int index)
    {
        result.push_back(item);
        if (index >= nums.size())
        {
            return;
        }

        for (int i = index;i < nums.size();i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            item.push_back(nums[i]);
            backtracking(nums, i + 1); // 递归
            item.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end

