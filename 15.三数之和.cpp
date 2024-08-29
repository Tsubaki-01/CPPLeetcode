/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int left;
        int right;
        int i = 0;
        while (i < nums.size() - 2)
        {
            int t = nums[i];
            left = i + 1;
            right = nums.size() - 1;

            if (t > 0)
                break;

            while (left < right)
            {
                if (nums[left] + nums[right] == 0 - t)
                {
                    res.push_back(vector<int>{t, nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    left++;
                }
                else if (nums[left] + nums[right] > 0 - t)
                {
                    right--;
                }
                else left++;
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
            i++;
        }
        return res;
    }
};
// @lc code=end

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size() - 2;i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }

        }
        return result;
    }
};
 */