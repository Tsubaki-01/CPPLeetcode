// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem560.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.18%)
 * Likes:    2457
 * Dislikes: 0
 * Total Accepted:    524.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
 *
 * 子数组是数组中元素的连续非空序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

 // 超时 O(n^2)
 // 前缀和
  /*
  class Solution
  {
  public:
      int subarraySum(vector<int>& nums, int k)
      {
          int res = 0;
          int sum = 0;
          vector<int> prefix_sum(nums.size(), 0);
          for (int i = 0; i < nums.size(); i++)
          {
              sum += nums[i];
              prefix_sum[i] = sum;
              if (sum == k)
                  res++;
          }

          for (int len = 1; len <= nums.size(); len++)
          {
              for (int i = 1; i <= nums.size() - len; i++)
              {
                  if (prefix_sum[i + len - 1] - prefix_sum[i - 1] == k)
                      res++;
              }
          }
          return res;
      }
  };
  */

  // !!!!!!!!!   if (prefix_sum[i + len - 1] - prefix_sum[i - 1] == k)  res++;

  // 前缀和+哈希记录前缀和出现的次数

  /*
  使用前缀和的方法可以解决这个问题，因为我们需要找到和为k的连续子数组的个数。
  通过计算前缀和，我们可以将问题转化为求解两个前缀和之差等于k的情况。
  假设数组的前缀和数组为prefixSum，其中prefixSum[i]表示从数组起始位置到第i个位置的元素之和。
  那么对于任意的两个下标i和j（i < j），如果prefixSum[j] - prefixSum[i] = k，
  即从第i个位置到第j个位置的元素之和等于k，那么说明从第i+1个位置到第j个位置的连续子数组的和为k。
  通过遍历数组，计算每个位置的前缀和，并使用一个哈希表来存储每个前缀和出现的次数。
  在遍历的过程中，我们检查是否存在prefixSum[j] - k的前缀和，
  初始时，哈希表中包含一对 0: 1，要覆盖前缀和恰好为k的情况。
  如果存在，说明从某个位置到当前位置的连续子数组的和为k，我们将对应的次数累加到结果中。
  这样，通过遍历一次数组，我们可以统计出和为k的连续子数组的个数，并且时间复杂度为O(n)，其中n为数组的长度。
   */
class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int res = 0;
        int sum = 0;
        vector<int> prefix_sum(nums.size(), 0);
        unordered_map<int, int> prefix_cnt;
        prefix_cnt[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefix_sum[i] = sum;
            if (prefix_cnt.find(sum - k) != prefix_cnt.end())
                res += prefix_cnt[sum - k];
            prefix_cnt[sum]++; // 最后再加入哈希表，覆盖k=0的情况
        }
        return res;
    }
};
// @lc code=end


// 超时 O(n^2)
// 滑动窗口
/*
class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int res = 0;
        int size = nums.size();
        int sum = 0;

        for (int len = 1;len <= size;len++)
        {
            sum = accumulate(nums.begin(), nums.begin() + len, 0);
            if (sum == k)
                res++;
            for (int i = 1;i <= size - len;i++)
            {
                sum -= nums[i - 1];
                sum += nums[i + len - 1];
                if (sum == k)
                    res++;
            }
        }
        return res;
    }
};
 */

