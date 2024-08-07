/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int res;
    int traversal(TreeNode* root)//0 无覆盖 1 有覆盖 2 有摄像头
    {
        if (root == nullptr)
            return 1;
        int left = traversal(root->left);
        int right = traversal(root->right);

        if (left == 0 || right == 0)
        {
            ++res;
            return 2;
        }
        if (left == 2 || right == 2)
        {
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (traversal(root) == 0)
            ++res;
        return res;
    }
};
// @lc code=end

