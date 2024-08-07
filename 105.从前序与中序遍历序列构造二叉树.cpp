/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* function(vector<int>& preorder, int preHead, int preRear, vector<int>& inorder, int inHead, int inRear)
    {
        if (preRear - preHead == 1)
        {
            TreeNode* root = new TreeNode(preorder[preHead]);
            return root;
        }
        int mid = preorder[preHead];
        TreeNode* root = new TreeNode(mid);
        int index = inHead;
        for (;index < inRear;index++)
        {
            if (inorder[index] == mid) break;
        }
        if (index > inHead) root->left = function(preorder, preHead + 1, preHead + 1 + index - inHead, inorder, inHead, index);
        if (index < inRear - 1) root->right = function(preorder, preHead + index - inHead + 1, preRear, inorder, index + 1, inRear);
        return root;


    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) return nullptr;
        return function(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end

