/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
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
// 双指针
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0 || s.size() == 1)
            return s.size();
        unordered_map<int, unordered_set<char>> map;
        int res = 1;

        for (int left = 0;left < s.size();left++)
        {
            map[left].insert(s[left]);
            int t = 1;
            for (int right = left + 1;right < s.size();right++)
            {
                if (map[left].count(s[right]) == 0)
                {
                    map[left].insert(s[right]);
                    t++;
                    res = max(res, t);
                }
                else break;
            }
        }
        return res;
    }
};
// @lc code=end

