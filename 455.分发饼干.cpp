/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include<iostream>
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        int index = s.size() - 1;
        for (int i = g.size() - 1;i >= 0;i--)
        {
            if (index < 0) break;
            if (s[index] >= g[i])
                cnt++, index--;
        }
        return cnt;
    }
};
// @lc code=end

