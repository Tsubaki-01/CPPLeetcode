// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem41.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode.cn/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (45.16%)
 * Likes:    2185
 * Dislikes: 0
 * Total Accepted:    430.8K
 * Total Submissions: 949.3K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,0]
 * 输出：3
 * 解释：范围 [1,2] 中的数字都在数组中。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 解释：1 在数组中，但 2 没有。
 *
 * 示例 3：
 *
 *
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 解释：最小的正数 1 没有出现。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// 空间开销主要在哈希表，用nums数组优化成原地哈希: f[n]=nums[n-1]
// 大小为n的数组，最大的正整数只有可能在[1,n]中
// 时间O(n) 空间O(1)
class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return nums.size() + 1;
    }
};


// @lc code=end


// 时间O(n) 空间O(n)
/*
class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        unordered_set<int> set;
        int max_tmp = INT_MIN;
        int min_tmp = INT_MAX;
        for (auto& num : nums)
        {
            if (num > 0)
            {
                set.insert(num);
                max_tmp = max(max_tmp, num);
                min_tmp = min(min_tmp, num);
            }
        }

        if (min_tmp > 1)
            return 1;

        while (min_tmp <= max_tmp)
        {
            if (set.find(min_tmp) == set.end())
                return min_tmp;
            else min_tmp++;
        }

        return min_tmp;
    }
};
 */


 /*
 // 空间开销主要在哈希表，用nums数组优化成原地哈希: f[n]=nums[n-1]
 // 大小为n的数组，最大的正整数只有可能在[1,n]中
 // 时间O(n) 空间O(1)


// 法一

 class Solution
 {
 public:
     int firstMissingPositive(vector<int>& nums)
     {
         for (int i = 0; i < nums.size(); i++)
         {
             while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
             {
                 swap(nums[i], nums[nums[i] - 1]);
             }
         }
         for (int i = 0; i < nums.size(); i++)
         {
             if (nums[i] != i + 1)
                 return i + 1;
         }

         return nums.size() + 1;
     }
 };
  */


  /*

// 法二

class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int& num : nums)
        {
            if (num <= 0)
            {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int num = abs(nums[i]);
            if (num <= n)
            {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};
   */