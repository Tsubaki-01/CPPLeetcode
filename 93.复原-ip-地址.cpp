// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
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
    vector<string> result;
    string ip;
    int cnt;

    bool isValid(string s)
    {
        if (s.size() > 1 && s[0] == '0')
            return false;
        int num = stoi(s);
        if (num < 0 || num>255)
            return false;
        return true;
    }

    void backtracking(string& s, int index)
    {
        if (cnt == 4)
        {
            if (index >= s.size())
            {
                ip.pop_back();
                result.push_back(ip);
            }
            return;
        }

        for (int i = index;i < s.size();i++)
        {
            if (isValid(s.substr(index, i + 1 - index)))
            {
                ip += s.substr(index, i + 1 - index);
                ip.push_back('.');
                cnt++;
            }
            else break;
            backtracking(s, i + 1); // 递归
            cnt--;
            ip.erase(ip.begin() + index + cnt, ip.end());
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end

