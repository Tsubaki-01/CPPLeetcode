/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int at = -1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (target < nums[middle]) {
                right = middle - 1;
            }
            else if (target > nums[middle]) {
                left = middle + 1;
            }
            else {
                at = middle;
                break;
            }
        }
        if (at == -1)
            return { -1, -1 };
        else {
            left = at;
            right = at;
            while (left > 0 && nums[left - 1] == target) {
                left = left - 1;
            }
            while (right < nums.size() - 1 && nums[right + 1] == target) {
                right = right + 1;
            }
            return { left, right };
        }
    }
};
// @lc code=end

