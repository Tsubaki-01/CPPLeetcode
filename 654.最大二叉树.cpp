/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        if (nums.size() == 1)
        {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }

        int maxValue = *max_element(nums.begin(), nums.end());
        int index = distance(nums.begin(), find(nums.begin(), nums.end(), maxValue));
        TreeNode* root = new TreeNode(maxValue);

        vector<int> left(nums.begin(), nums.begin() + index);
        root->left = constructMaximumBinaryTree(left);

        vector<int> right(nums.begin() + index + 1, nums.end());
        root->right = constructMaximumBinaryTree(right);

        return root;

    }
};
// @lc code=end

