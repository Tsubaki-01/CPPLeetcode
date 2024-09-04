/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 *
 * https://leetcode.cn/problems/rotate-array/description/
 *
 * algorithms
 * Medium (45.36%)
 * Likes:    2229
 * Dislikes: 0
 * Total Accepted:    970.3K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右轮转 1 步: [7,1,2,3,4,5,6]
 * 向右轮转 2 步: [6,7,1,2,3,4,5]
 * 向右轮转 3 步: [5,6,7,1,2,3,4]
 *
 *
 * 示例 2:
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 * 解释:
 * 向右轮转 1 步: [99,-1,-100,3]
 * 向右轮转 2 步: [3,99,-1,-100]
 *
 * 进阶：
 * 尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// 轮转可以看成是将前几个元素复制到最后k个元素后面
// 可以看成是，前n-k个元素绕最后k个元素旋转之后，再翻转回原来的顺序

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end




/*

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        vector<int> res(nums.end() - k, nums.end());
        for (int i = 0; i < nums.size() - k; i++)
            res.push_back(nums[i]);
        nums = res;
    }
};
 */


 /*
class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        vector<int> tmp(2 * nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            tmp[i] = nums[i];
            tmp[i + nums.size()] = nums[i];
        }
        nums = vector<int>(tmp.begin() + nums.size() - k, tmp.end() - k);
    }
};
  */