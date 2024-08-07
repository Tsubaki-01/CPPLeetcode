/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    TreeNode* pre = nullptr;
    int count;
    int maxcount = INT_MIN;
    vector<int> result;
    void traversal(TreeNode* node)
    {
        if (!node)
            return;
        if (node->left) traversal(node->left);

        if (!pre) count = 1;
        else if (pre->val == node->val) count++;
        else count = 1;
        pre = node;
        if (count > maxcount)
        {
            maxcount = count;
            result.clear();
            result.push_back(node->val);
        }
        else if (count == maxcount) result.push_back(node->val);

        if (node->right) traversal(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return result;
    }
};
// @lc code=end

