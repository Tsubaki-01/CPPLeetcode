// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem128.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (51.56%)
 * Likes:    2179
 * Dislikes: 0
 * Total Accepted:    735.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:

    int longestConsecutive(vector<int>& nums)
    {
        // 集合，寻找每个连续序列中起始的数，保证数组中每个数只遍历一遍
        unordered_set<int> set(nums.begin(), nums.end());

        int res = 0;
        for (auto& num : set)
        {
            if (set.find(num - 1) != set.end())
                continue;
            else
            {
                int t = 0;
                int n = num;
                while (set.find(n++) != set.end())
                {
                    t++;
                }
                res = max(res, t);
            }
        }
        return res;
    }
};
// @lc code=end



// ！！！！并查集！！！！

/*
class Solution
{
public:
    unordered_map<int, int> father;
    // 并查集里寻根的过程
    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
    }

    // 判断 u 和 v是否找到同一个根
    bool isSame(int u, int v)
    {
        int uRoot = find(u);
        int vRoot = find(v);
        return uRoot == vRoot;
    }

    // 将v->u 这条边加入并查集
    void join(int parent, int child)
    {
        int parentRoot = find(parent); // 寻找u的根
        int childRoot = find(child); // 寻找v的根
        if (parentRoot == childRoot) return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
        father[childRoot] = parentRoot;
    }

    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> set(nums.begin(), nums.end());
        for (auto& num : set)
        {
            father[num] = num;
        }
        for (auto& num : set)
        {
            if (father.count(num - 1) > 0)
            {
                join(num, num - 1);
            }
            if (father.count(num + 1) > 0)
            {
                join(num + 1, num);
            }
        }
        int res = 0;
        for (auto& i : nums)
        {
            res = max(res, find(i) - i + 1);
        }
        return res;
    }
};
 */


 // 错误解法，这样子只能向两边拓展，不能合并两个相邻的区间。
 // ！！！！！！合并区间！！！！！！ --> 将两个集合变成一个集合 --> 并查集

 /* // <边界，<另一边界，长度>>
         unordered_map<int, pair<int, int>> map;
         int res = -1;
         for (auto& num : nums)
         {
             if (map.find(num) != map.end())
             {
                 auto t = map[num];
                 map.erase(num);
                 if (num < t.first)
                 {
                     map[num - 1] = pair<int, int>{ t.first,t.second + 1 };
                     map[t.first] = pair<int, int>{ num - 1,t.second + 1 };
                 }
                 else
                 {
                     map[num + 1] = pair<int, int>{ t.first,t.second + 1 };
                     map[t.first] = pair<int, int>{ num + 1,t.second + 1 };
                 }
                 res = max(res, t.second + 1);
             }
             else
             {
                 map[num - 1] = pair<int, int>{ num + 1,1 };
                 map[num + 1] = pair<int, int>{ num - 1,1 };
                 res = max(res, 1);
             }
         }
         return res; */


