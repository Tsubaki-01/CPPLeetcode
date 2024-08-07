// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem202.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int t = n;
        while (1)
        {
            if (t == 1)
            {
                return true;
            }
            int res = 0;
            while (t != 0)
            {
                int a = t / 10;
                int b = t % 10;
                t = a;
                res += b * b;
            }
            if (set.find(res) != set.end())
            {
                return false;
            }
            else
            {
                set.insert(res);
                t = res;
            }


        }
    }
};
// @lc code=end

