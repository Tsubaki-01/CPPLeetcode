// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem71.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
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
    string simplifyPath(string path) {
        vector<string> paths = split(path, '/');
        vector<string> res;
        for (auto i : paths)
        {
            if (!res.empty() && i == "..")
                res.pop_back();
            else if (i != ".." && i != ".") res.push_back(i);
        }
        string ans;
        if (res.empty())
            return "/";
        else
        {
            for (auto name : res)
            {
                ans += "/" + name;
            }
        }
        return ans;
    }
private:
    vector<string> split(const string& s, char delim)
    {
        vector<string> res;
        string cur;
        for (auto ch : s)
        {
            if (ch == delim && !cur.empty())
                res.push_back(move(cur));
            else if (ch != delim) cur += ch;
        }
        if (!cur.empty())
            res.push_back(move(cur));
        return res;
    }
};
// @lc code=end

