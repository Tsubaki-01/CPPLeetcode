/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <string>
#include<algorithm>
#include<vector>
using namespace std;

// @lc code=start


class Solution {
public:
    string reverseWords(string s) {
        deleteSpace(s);
        reverse(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while (j < s.size())
        {
            while (j < s.size() && s[j] != ' ')
            {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);
            i = ++j;
        }
        return s;
    }
private:
    void deleteSpace(string& s)
    {
        int size = s.size();
        int fast = 0;
        int slow = 0;
        while (size > 0 && fast < size - 1 && s[fast] == ' ')
        {
            fast++;
        }
        while (fast < size)
        {

            if (s[fast] == ' ' && s[fast - 1] == ' ') fast++;
            else
            {

                s[slow] = s[fast];
                slow++;
                fast++;

            }

        }
        if (slow - 1 > 0 && s[slow - 1] == ' ')
            s.resize(slow - 1);
        else s.resize(slow);
    }
};
// @lc code=end

