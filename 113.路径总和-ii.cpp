/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> result;
    void function(vector<int>& path, TreeNode* root, int rest)
    {
        path.push_back(root->val);
        if (!root->left && !root->right && rest == root->val)
        {
            result.push_back(path);
            return;
        }
        if (!root->left && !root->right && rest != root->val) return;
        if (root->left)
        {
            function(path, root->left, rest - root->val);
            path.pop_back();
        }
        if (root->right)
        {
            function(path, root->right, rest - root->val);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return result;
        vector<int > path;
        function(path, root, targetSum);
        return result;
    }
};
// @lc code=end

