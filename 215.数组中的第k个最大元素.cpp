// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem215.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include<vector>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);

        for (int i = k;i < nums.size();i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
// @lc code=end

/* class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int k)
    {
        if (left == right)
            return nums[left];
        int mid = nums[left + (right - left) / 2];
        int l = left;
        int r = right;
        while (l < r)
        {
            while (nums[l] < mid)
                l++;
            while (nums[r] > mid)
                r--;
            if (l < r)
            {
                swap(nums[l], nums[r]);
                if (nums[l] == nums[r])
                {
                    l++; r--;
                }
            }

        }

        int bigger = right - r;
        if (bigger >= k)
            return quickSelect(nums, r + 1, right, k);
        else return quickSelect(nums, left, r, k - bigger);
    }


    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
}; */