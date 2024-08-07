/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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

    int rootSum(TreeNode* root, long targetSum)
    {
        if (root == nullptr)
            return 0;
        int res = 0;
        if (root->val == targetSum)
            res++;

        res += rootSum(root->left, targetSum - root->val);
        res += rootSum(root->right, targetSum - root->val);
        return res;
    }


    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return 0;
        int res = rootSum(root, targetSum);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);

        return res;
    }
};
// @lc code=end

