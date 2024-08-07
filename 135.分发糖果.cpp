// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem135.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include<iostream>
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include<numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1)
            return ratings.size();
        vector<int> res(ratings.size(), 1);
        for (int i = 0;i < ratings.size() - 1;i++)
        {
            if (ratings[i + 1] > ratings[i] && res[i + 1] <= res[i])
                res[i + 1] = res[i] + 1;
        }
        for (int i = ratings.size() - 1;i > 0;i--)
        {
            if (ratings[i - 1] > ratings[i] && res[i - 1] <= res[i])
                res[i - 1] = res[i] + 1;
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};
// @lc code=end

