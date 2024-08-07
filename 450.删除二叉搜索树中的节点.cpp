/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* function(TreeNode* oldRoot, TreeNode* oldRootRight)
    {
        if (!oldRootRight)
            return nullptr;
        if (oldRootRight->left == nullptr)  //***考虑
        {
            oldRootRight->left = oldRoot->left;
            return oldRootRight;
        }
        TreeNode* cur = oldRootRight;
        while (cur->left->left != nullptr)
        {
            cur = cur->left;
        }
        TreeNode* newRoot = cur->left;
        if (newRoot->right) //***考虑
            cur->left = newRoot->right;
        else    cur->left = nullptr;
        newRoot->left = oldRoot->left;
        newRoot->right = oldRoot->right;

        return newRoot;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {

            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;
            TreeNode* newRoot = function(root, root->right);
            delete root;
            return newRoot;
        }
        if (key < root->val && root->left)
            root->left = deleteNode(root->left, key);

        else if (key > root->val && root->right)
            root->right = deleteNode(root->right, key);

        return root;

    }
};
// @lc code=end

