/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> sta;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while (!sta.empty() || cur)
        {
            while (cur)
            {
                sta.push(cur);
                cur = cur->left;
            }
            cur = sta.top();
            sta.pop();
            if (pre && cur->val <= pre->val) return false;
            pre = cur;
            cur = cur->right;
        }
        return true;
    }
};
// @lc code=end

