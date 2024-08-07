// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem347.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> frequency;
        for (int i = 0;i < nums.size();i++)
        {
            frequency[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto i : frequency)
        {
            pq.push(i);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> res(k);
        for (int i = k - 1;i >= 0;i--)
        {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
    class Compare
    {
    public:
        bool operator()(const pair<int, int>& child, const pair<int, int>& parent)
        {
            return child.second > parent.second;
        }
    };
};
// @lc code=end

