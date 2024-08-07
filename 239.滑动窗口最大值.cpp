/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
using namespace std;
// @lc code=start
class Window
{
public:
    int front()
    {
        return queue.front();
    }

    void pop(int out)
    {
        if (!queue.empty() && out == this->front())
        {
            queue.pop_front();
        }
    }

    int getMax()
    {
        return this->front();
    }

    void push(int in)
    {
        if (!queue.empty() && in > this->front())
        {
            queue.clear();
        }
        else if (!queue.empty() && in <= this->front())
        {
            while (in > queue.back())
                queue.pop_back();
        }
        queue.push_back(in);
    }

private:
    deque<int> queue;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Window window;
        vector<int> res;
        for (int i = 0;i < k;i++)
        {
            window.push(nums[i]);
        }
        res.push_back(window.getMax());
        for (int i = 1;i + k - 1 < nums.size();i++)
        {
            window.pop(nums[i - 1]);
            window.push(nums[i + k - 1]);
            res.push_back(window.getMax());
        }
        return res;
    }
};

// @lc code=end

