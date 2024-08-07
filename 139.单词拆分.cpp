// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem139.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
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
// 排列问题 完全背包 爬台阶


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty())
            return false;

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;


        for (int j = 0;j < dp.size();++j)
            for (int i = 0;i < wordDict.size();++i)
                if (dp[j] == false && wordDict[i].size() <= j) // 已经能做到的就不要去再迭代，可能会导致true的值更新成false
                    if (wordDict[i].compare \
                        (string(s, j - wordDict[i].size(), wordDict[i].size())) == 0)
                        dp[j] = dp[j - wordDict[i].size()];

        return dp.back();

    }
};
// @lc code=end



/* class Solution {
private:
    bool backtracking(string& s, unordered_set<string>& set,
        vector<bool>& memory, int index)
    {
        if (index >= s.size())
            return true;

        if (memory[index] == false)
            return false;

        for (int i = index;i < s.size();++i)
        {
            string t = s.substr(index, i - index + 1);
            if (set.find(t) != set.end())
                if (backtracking(s, set, memory, i + 1))
                    return true;
        }
        memory[index] = false;
        return false;

    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size(), true);
        return backtracking(s, set, memory, 0);
    }
}; */