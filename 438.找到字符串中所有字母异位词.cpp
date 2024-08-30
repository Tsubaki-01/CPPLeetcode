// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem438.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.38%)
 * Likes:    1495
 * Dislikes: 0
 * Total Accepted:    493.9K
 * Total Submissions: 924.4K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *
 *
 * 示例 1:
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 示例 2:
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// 固定大小的滑动窗口
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;

        int p_size = p.size();
        int s_size = s.size();

        if (p_size > s_size)
            return res;

        vector<int> p_cnt(26, 0);
        vector<int> s_cnt(26, 0);

        for (auto& c : p)
            p_cnt[c - 'a']++;
        for (int i = 0;i < p_size;i++)
            s_cnt[s[i] - 'a']++;

        if (s_cnt == p_cnt)
            res.push_back(0);

        for (int i = 1;i < s_size - p_size + 1;i++)
        {
            s_cnt[s[i - 1] - 'a']--;
            s_cnt[s[i + p_size - 1] - 'a']++;

            if (s_cnt == p_cnt)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

