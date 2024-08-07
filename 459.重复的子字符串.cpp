/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>
#include<algorithm>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0)
            return false;
        int next[s.size()];
        getNext(next, s);
        return next[s.size() - 1] != 0 && (s.size()) % (s.size() - next[s.size() - 1]) == 0;
    }
private:
    void getNext(int* next, string s)
    {
        int j = 0;
        next[j] = 0;
        for (int i = 1;i < s.size();i++)
        {
            while (j > 0 && s[i] != s[j])
                j = next[j - 1];
            if (s[i] == s[j])
                j++;
            next[i] = j;
        }
    }
};
// @lc code=end

