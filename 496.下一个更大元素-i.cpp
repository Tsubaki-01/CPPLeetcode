/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        if (nums1.empty())
            return res;
        unordered_map<int, int> map;
        stack<int> sta;
        sta.push(nums2[0]);
        for (int i = 0;i < nums1.size();i++)
        {
            map[(nums1[i])] = i;
        }

        for (int i = 0;i < nums2.size();i++)
        {
            if (nums2[i] < sta.top())
                sta.push(nums2[i]);
            else if (nums2[i] == sta.top())
                sta.push(nums2[i]);
            else {
                while (!sta.empty() && nums2[i] > sta.top())
                {
                    if (map.count(sta.top()) > 0)
                        res[map[sta.top()]] = nums2[i];
                    sta.pop();
                }
            }
            sta.push(nums2[i]);
        }

        return res;

    }
};
// @lc code=end

