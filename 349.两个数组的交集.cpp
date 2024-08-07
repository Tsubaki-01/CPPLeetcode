/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> map;
        vector<int> res;
        for (auto i : nums1)
        {
            map[i] = 1;
        }
        for (auto i : nums2)
        {
            if (map.count(i) && map[i] == 1)
            {
                map[i]--;
                res.emplace_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

