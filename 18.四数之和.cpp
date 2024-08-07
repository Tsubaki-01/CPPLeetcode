/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include <vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4) return result;
        for (int i = 0; i < nums.size() - 3;i++)
        {
            if (nums[i] > target && nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1;j < nums.size() - 2;j++)
            {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] > 0)
                {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {

                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] == target)
                    {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                    if (left < right && (long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    if (left<right && (long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

