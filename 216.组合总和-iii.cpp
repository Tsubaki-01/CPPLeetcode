/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
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
    void backtracking(int k, int rest, int num)
    {
        if (item.size() == k)
        {
            if (rest == 0)
                result.push_back(item);
            return;
        }
        int size = item.size();
        for (int i = num;i <= 9 - (k - size) + 1;i++)
        {
            if (rest - i < 0) break;
            item.push_back(i);
            backtracking(k, rest - i, i + 1);
            item.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return result;
    }
};
// @lc code=end

