// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem860.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
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
    bool lemonadeChange(vector<int>& bills) {
        vector<int> charge(2, 0);
        for (auto item : bills)
        {
            if (item == 5)
                charge[0]++;
            else if (item == 10)
                charge[1]++, charge[0]--;
            else
            {
                if (charge[1] > 0) charge[1]--, charge[0]--;
                else charge[0] -= 3;
            }
            if (charge[0] < 0 || charge[1] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

