/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        stack<pair<TreeNode*, int >> stack;
        stack.push(pair<TreeNode*, int>(root, targetSum - root->val));
        while (!stack.empty())
        {
            pair<TreeNode*, int> tmp;
            tmp = stack.top();
            stack.pop();
            if (!tmp.first->left && !tmp.first->right && tmp.second == 0)
            {
                return true;
            }
            if (tmp.first->right) stack.push(pair<TreeNode*, int>(tmp.first->right, tmp.second - tmp.first->right->val));
            if (tmp.first->left) stack.push(pair<TreeNode*, int>(tmp.first->left, tmp.second - tmp.first->left->val));
        }
        return false;
    }
};
// @lc code=end

