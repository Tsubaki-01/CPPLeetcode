// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
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
    string item;
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    void backtracking(int length, int index, string& digits)
    {
        if (item.size() == length)
        {
            result.push_back(item);
            return;
        }
        int size = item.size();
        int num = int(digits[index]) - '0';
        for (auto i : letterMap[num])
        {
            item.push_back(i);
            backtracking(length, index + 1, digits); // 递归
            item.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return result;
        backtracking(digits.size(), 0, digits);
        return result;
    }
};
// @lc code=end

