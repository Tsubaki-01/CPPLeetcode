// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0;i < nums.size();i++)
        {
            if (map.count(target - nums[i]))
            {
                return vector<int>{i, map[target - nums[i]]};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return vector<int>{};
    }
};
// @lc code=end

