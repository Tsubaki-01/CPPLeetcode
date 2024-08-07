/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <string>
#include<algorithm>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        int next[needle.size()];
        getNext(next, needle);
        int i = 0;
        int j = 0;
        for (;i < haystack.size();i++)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j >= needle.size())
                return i - j + 1;
        }
        return -1;

    }

private:
    void getNext(int* next, string needle)
    {
        int j = 0;
        next[j] = 0;
        for (int i = 1;i < needle.size();i++)
        {
            while (j > 0 && needle[i] != needle[j])
                j = next[j - 1];
            if (needle[i] == needle[j])
                j++;
            next[i] = j;
        }
    }
};
// @lc code=end

