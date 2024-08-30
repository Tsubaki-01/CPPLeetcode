// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem3.h"

using namespace std;
// @before-stub-for-debug-end

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
// 滑动窗口
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s.size();

        int res = 0;
        int left = 0;
        int right = 0;

        unordered_set<char> set;

        while (right < s.size() && left <= right)
        {
            while (set.find(s[right]) != set.end())
            {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            right++;
            res = max(res, right - left);
        }

        return res;

    }
};
// @lc code=end


/*
// 双指针
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s.size();

        int t = 0;
        int res = 0;
        int left = 0;
        int right = 0;

        unordered_set<char> set;

        while (right < s.size() && left <= right)
        {
            if (set.count(s[right]) == 0)
            {
                set.insert(s[right]);
                t++;
                right++;
                res = max(res, t);
            }
            else
            {
                while (s[left] != s[right])
                {
                    set.erase(s[left]);
                    left++;
                    t--;
                }
                left++;
                right++;
            }
        }

        return res;

    }
};
 */