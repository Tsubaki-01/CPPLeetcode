// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem321.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
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
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);

        int len1 = nums1.size();
        int len2 = nums2.size();

        for (int i = max(0, k - len2);i <= min(k, len1);i++)
        {
            vector<int> temp;

            vector<int> t1 = maxK(nums1, i);
            vector<int> t2 = maxK(nums2, k - i);

            auto iter1 = t1.begin();
            auto iter2 = t2.begin();

            while (iter1 != t1.end() || iter2 != t2.end())
            {
                temp.push_back(
                    lexicographical_compare(iter1, t1.end(),
                        iter2, t2.end()) ?
                    *iter2++ : *iter1++
                );
            }

            res = lexicographical_compare(
                res.begin(), res.end(), temp.begin(), temp.end()
            ) ? temp : res;
        }

        return res;
    }

    vector<int> maxK(vector<int>v, int k)
    {
        int len = v.size();
        if (len <= k)
            return v;
        vector<int> res;
        res.push_back(v[0]);
        int pop = 0;
        for (int i = 1;i < len;i++)
        {
            while (!res.empty() && v[i] > res.back() && ++pop <= len - k)
                res.pop_back();
            res.push_back(v[i]);
        }
        res.resize(k);
        return res;
    }
};
// @lc code=end

