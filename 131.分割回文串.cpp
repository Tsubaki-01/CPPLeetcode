// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem131.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
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
    vector<vector<string>> result;
    vector<string> item;
    vector<vector<bool>> isPalindrome;
    void getIsPalindrome(string& s)
    {
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = 0;i < s.size();i++)
            isPalindrome[i][i] = true;
        for (int j = 1;j < s.size();j++)
            for (int i = 0;i < j;i++)
                if (s[i] == s[j])
                    isPalindrome[i][j] = ((i + 1 <= j - 1) ?
                        isPalindrome[i + 1][j - 1] : true);

    }

    void backtracking(string& s, int index)
    {
        if (index >= s.size())
        {
            result.push_back(item);
            return;
        }

        for (int i = index;i < s.size();i++)
        {
            if (isPalindrome[index][i])
                item.push_back(s.substr(index, i - index + 1));
            else continue;
            backtracking(s, i + 1); // 递归
            item.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        getIsPalindrome(s);
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end

