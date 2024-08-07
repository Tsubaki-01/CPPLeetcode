// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem214.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
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
class Solution {
public:
    string shortestPalindrome(string s) {
        string t(s);
        reverse(t.begin(), t.end());

        vector<int>next = getNext(s);

        int j = 0;
        for (int i = 0;i < t.size();i++)
        {
            while (j > 0 && t[i] != s[j])
                j = next[j - 1];
            if (t[i] == s[j])
                j++;
        }

        string add = s.substr(j);
        reverse(add.begin(), add.end());
        return add + s;

    }

    vector<int> getNext(string s)
    {
        vector<int> next(s.size(), 0);
        int j = 1;
        int i = 0;

        while (j < s.size())
        {
            while (i > 0 && s[i] != s[j])
            {
                i = next[i - 1];
            }


            if (s[i] == s[j])
                i++;

            next[j] = i;
            j++;

        }
        return next;
    }
};
// @lc code=end

