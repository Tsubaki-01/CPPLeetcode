// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem49.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (68.50%)
 * Likes:    1969
 * Dislikes: 0
 * Total Accepted:    797.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 *
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 示例 2:
 *
 *
 * 输入: strs = [""]
 * 输出: [[""]]
 *
 *
 * 示例 3:
 *
 *
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 *
 *
* 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
* 输出 : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 利用按照字母顺序排序过后的字符串作为哈希表的键值
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        string t;
        for (auto& s : strs)
        {
            t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        for (auto& item : map)
        {
            res.push_back(item.second);
        }
        return res;
    }
};
// @lc code=end

/* class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<int>> tabs;
        vector<vector<string>> res;

        for (auto& s : strs)
        {
            vector<int> cur(26, 0);
            for (auto& c : s)
                cur[c - 'a']++;

            int flag = 1;
            for (int i = 0;i < res.size();i++)
            {
                int t = 0;
                for (int j = 0;j < 26;j++)
                    if (tabs[i][j] != cur[j])
                    {
                        t = 1;
                        break;
                    }
                if (t) continue;
                res[i].push_back(s);
                flag = 0;
            }
            if (flag)
            {
                res.push_back({ s });
                tabs.push_back(cur);
            }
        }
        return res;
    }
}; */