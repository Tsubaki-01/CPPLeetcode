/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
            item.push_back(nums[i]);
            backtracking(nums, i + 1); // 递归
            item.pop_back();
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end

