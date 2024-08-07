/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0;i < s.size();i++)
        {
            if (s[i] == '(')
                stack.push(')');
            else if (s[i] == '[')
                stack.push(']');
            else if (s[i] == '{')
                stack.push('}');
            else if (!stack.empty() && s[i] == stack.top())
                stack.pop();
            else return false;
        }
        if (stack.empty())
            return true;
        else return false;
    }
};
// @lc code=end

