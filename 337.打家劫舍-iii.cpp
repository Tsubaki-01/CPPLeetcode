// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem337.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
/* struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
}; */
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // 动态规划

class Solution {
public:
    vector<int> function(TreeNode* root)
    {
        vector<int> vec(2, 0);
        if (root == nullptr) return vec;

        vector<int> left = function(root->left);
        vector<int> right = function(root->right);
        // 不偷
        vec[0] = max(left[0], left[1]) +
            max(right[0], right[1]);

        //偷
        vec[1] = left[0] + right[0] + root->val;

        return vec;
    }

    int rob(TreeNode* root) {
        return max(function(root)[0], function(root)[1]);
    }
};
// @lc code=end
// 递归
/* class Solution {
public:
    unordered_map<TreeNode*, int> map;
    int traversal(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int res = 0;
        if (map[root]) return map[root];
        if (root->left && root->right)
            map[root] = max(traversal(root->left) + traversal(root->right),
                traversal(root->left->left) + traversal(root->left->right) + traversal(root->right->left) + traversal(root->right->right) + root->val);
        else if (!root->left && root->right)
            map[root] = max(traversal(root->right), traversal(root->right->left) + traversal(root->right->right) + root->val);
        else if (!root->right && root->left)
            map[root] = max(traversal(root->left), traversal(root->left->left) + traversal(root->left->right) + root->val);
        else map[root] = root->val;
        return map[root];
    }


    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        return traversal(root);
    }
}; */