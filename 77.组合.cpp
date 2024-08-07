/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
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
    void backtracking(int n, int k, int start) {
        if (item.size() == k) {
            result.push_back(item);
            return;
        }
        int size = item.size();
        for (int i = start;i <= size + n - k + 1;i++) {
            item.push_back(i);
            backtracking(n, k, i + 1); // 递归
            item.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};
// @lc code=end

