/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return nullptr;
        if (inorder.size() == 1)
        {
            TreeNode* root = new TreeNode(inorder[0]);
            return root;
        }

        int last = postorder.back();
        TreeNode* root = new TreeNode(last);
        auto split = find(inorder.begin(), inorder.end(), last);
        int index = distance(inorder.begin(), split);

        // if (index > 0)
        // {
        vector<int> newInorder(inorder.begin(), inorder.begin() + index);
        vector<int> newPostorder(postorder.begin(), postorder.begin() + index);
        root->left = buildTree(newInorder, newPostorder);
        // }
        // if (index < inorder.size() - 1)
        // {
        vector<int> newInorder2(inorder.begin() + index + 1, inorder.end());
        vector<int> newPostorder2(postorder.begin() + index, postorder.end() - 1);
        root->right = buildTree(newInorder2, newPostorder2);
        // }
        return root;
    }
};
// @lc code=end

