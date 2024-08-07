// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem738.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
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
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);

        for (int i = num.size() - 1;i > 0;--i)
        {
            if (num[i] == -1)
                num[i] = '9', --num[i - 1];
            if (num[i] >= num[i - 1])
                continue;
            else {
                for (int j = i;j < num.size();j++)
                    num[j] = '9';
                --num[i - 1];
            }
        }

        return stoi(num);
    }
};
// @lc code=end

