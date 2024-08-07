/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if (!root) return false;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty())
        {
            TreeNode* compare1 = que.front();
            que.pop();
            TreeNode* compare2 = que.front();
            que.pop();
            if (!compare1 && !compare2) continue;
            else if (!compare1 || !compare2 || compare1->val != compare2->val) return false;

            que.push(compare1->left);
            que.push(compare2->right);
            que.push(compare1->right);
            que.push(compare2->left);
        }
        return true;
    }
};
// @lc code=end

