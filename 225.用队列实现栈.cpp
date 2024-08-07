/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
using namespace std;
// @lc code=start
class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        queue1.push(x);
    }

    int pop() {
        while (queue1.size() != 1)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int t = queue1.front();
        queue1.pop();
        while (!queue2.empty())
        {
            queue1.push(queue2.front());
            queue2.pop();
        }

        return t;
    }

    int top() {
        int t = this->pop();
        queue1.push(t);
        return t;
    }

    bool empty() {
        return queue1.empty() && queue2.empty();
    }
private:
    queue<int> queue1;
    queue<int> queue2;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 // @lc code=end

