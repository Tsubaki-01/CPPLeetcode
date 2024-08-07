// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem452.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
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
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 0;
        if (points.empty())
            return res;
        ++res;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        for (auto i : points)
            cout << i[0] << i[1] << endl;
        for (int i = 1;i < points.size();i++)
        {
            if (points[i][0] > points[i - 1][1])
                ++res;
            else {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }
        return res;
    }
};
// @lc code=end

