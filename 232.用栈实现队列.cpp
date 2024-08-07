/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <string>
#include<algorithm>
#include<vector>
#include <stack>
using namespace std;
// @lc code=start
class MyQueue {
public:

    MyQueue() {

    }

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        if (stack_out.empty())
        {
            while (!stack_in.empty())
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int t = stack_out.top();
        stack_out.pop();
        return t;
    }

    int peek() {
        int t = this->pop();
        stack_out.push(t);
        return t;
    }

    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }
private:
    stack<int> stack_in;
    stack<int> stack_out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 // @lc code=end

