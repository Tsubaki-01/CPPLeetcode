/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        if (s.length() != t.length())
        {
            return false;
        }
        for (auto i : s)
        {
            if (map.count(i))
            {
                map[i]++;
            }
            else
            {
                map[i] = 1;
            }

        }

        for (auto i : t)
        {
            if (!map.count(i))
            {
                return false;
            }
            map[i]--;
            if (map[i] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

