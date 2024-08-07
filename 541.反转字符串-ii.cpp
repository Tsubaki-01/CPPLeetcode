/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

#include <string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        for (int i = 0;i < size - 1;i = i + 2 * k)
        {
            if (i + k > size - 1)
            {
                reverse(s.begin() + i, s.end());
            }
            else if (i + k < size - 1 && i + 2 * k>size - 1)
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
};
// @lc code=end

