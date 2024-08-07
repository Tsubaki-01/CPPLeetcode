/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        int size = s.size();
        for (int i = 0; i < size;i++)
        {
            if (stack.empty())
                stack.push(s[i]);
            else if (s[i] == stack.top())
                stack.pop();
            else stack.push(s[i]);
        }
        string res;
        while (!stack.empty())
        {
            res.push_back(stack.top());
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

