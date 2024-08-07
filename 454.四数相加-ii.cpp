/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> map;

        for (auto a : nums1)
        {
            for (auto b : nums2)
            {
                map[a + b]++;
            }
        }

        int cnt = 0;
        for (auto c : nums3)
        {
            for (auto d : nums4)
            {
                if (map.count(0 - (c + d)))
                {
                    cnt += map[0 - (c + d)];
                }
            }
        }

        return cnt;
    }
};
// @lc code=end

