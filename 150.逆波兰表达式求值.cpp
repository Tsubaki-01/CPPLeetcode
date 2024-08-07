/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
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
    int evalRPN(vector<string>& tokens) {
        stack <long long> stack;
        for (int i = 0;i < tokens.size();i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long num1 = stack.top();
                stack.pop();
                long long num2 = stack.top();
                stack.pop();
                if (tokens[i] == "+")
                    stack.push(num1 + num2);
                if (tokens[i] == "-")
                    stack.push(num2 - num1);
                if (tokens[i] == "*")
                    stack.push(num1 * num2);
                if (tokens[i] == "/")
                    stack.push(num2 / num1);
            }
            else stack.push(stoll(tokens[i]));
        }
        return stack.top();
    }
};
// @lc code=end

