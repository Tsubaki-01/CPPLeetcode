/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
    void backtracking(vector<int>& candidates, int rest, int index)
    {
        if (rest == 0)
        {
            result.push_back(item);
            return;
        }

        for (int i = index;i < candidates.size() && rest - candidates[i] >= 0;i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            item.push_back(candidates[i]);
            backtracking(candidates, rest - candidates[i], i + 1); // 递归
            item.pop_back();
        }
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};
// @lc code=end

