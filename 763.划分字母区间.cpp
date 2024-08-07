/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
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


    vector<int> partitionLabels(string s) {
        if (s.empty())
            return vector<int>{0};
        vector<int> res;
        int rightest[26] = { 0 };
        for (int i = 0;i < s.size();i++)
        {
            rightest[s[i] - 'a'] = i;
        }

        int left = 0;
        int right = 0;
        for (int i = 0;i < s.size();i++)
        {
            if (i > right)
            {
                res.push_back(right - left + 1);
                left = i;
            }
            right = max(right, rightest[s[i] - 'a']);
            if (right == s.size() - 1)
                break;
        }
        res.push_back(right - left + 1);

        return res;
    }
};
// @lc code=end

