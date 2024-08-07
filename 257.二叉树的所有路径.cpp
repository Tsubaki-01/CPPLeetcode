/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode* cur, string path, vector<string>& result)
    {
        path += to_string(cur->val);
        if (cur->left == nullptr && cur->right == nullptr)
        {
            result.push_back(path);
        }

        if (cur->left)
            traversal(cur->left, path + "->", result);
        if (cur->right)
            traversal(cur->right, path + "->", result);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> result;
        if (root == nullptr)
            return result;
        traversal(root, path, result);
        return result;
    }
};
// @lc code=end

