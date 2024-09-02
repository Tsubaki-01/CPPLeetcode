// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (46.04%)
 * Likes:    2974
 * Dislikes: 0
 * Total Accepted:    625.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {

    }
};
// @lc code=end

/*
class Solution
{
public:
    // 在字符串s中找到包含字符串t所有字符的最小子串
    string minWindow(string s, string t)
    {
        // 如果t的长度大于s的长度，则返回空字符串
        if (t.size() > s.size())
            return "";

        // 使用unordered_map来存储t中每个字符的个数
        unordered_map<int, int> t_cnt;
        for (auto& c : t)
        {
            t_cnt[c]++;
        }

        // 定义左右指针，初始位置都为0
        int left = 0, right = 0;
        // 定义最小子串的长度，初始值为INT_MAX
        int len = INT_MAX;
        // 定义计数器，记录当前窗口中包含t中字符的个数
        int count = 0;
        // 定义pos，记录最小子串的起始位置
        int pos = -1;

        // 当右指针小于s的长度时，循环继续
        while (right < s.size())
        {
            // 如果当前字符在t中，并且t中该字符的个数大于0，则计数器加1
            if (t_cnt.find(s[right]) != t_cnt.end()
                && --t_cnt[s[right]] >= 0)
            {
                count++;
            }

            // 当计数器等于t的长度时，说明当前窗口中包含了t中所有字符
            while (count == t.size() && left <= right)
            {
                // 如果当前窗口的长度小于最小子串的长度，则更新最小子串的长度和起始位置
                if (len > right - left + 1)
                {
                    pos = left;
                    len = right - left + 1;
                }

                // 如果当前字符在t中，并且t中该字符的个数大于0，则计数器减1
                if (t_cnt.find(s[left]) != t_cnt.end()
                    && ++t_cnt[s[left]] > 0)
                {
                    count--;
                }
                // 左指针右移
                left++;
            }
            // 右指针右移
            right++;
        }
        // 如果pos为-1，说明没有找到最小子串，返回空字符串；否则返回最小子串
        return pos == -1 ? "" : s.substr(pos, len);
    }
};

 */