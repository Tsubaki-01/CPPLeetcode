/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int maxDepth;
    int result;
    void findLeftMax(TreeNode* root, int depth)
    {

        if (depth > maxDepth && !root->left && !root->right)
        {
            maxDepth = depth;
            result = root->val;
        }

        if (root->left)
        {
            findLeftMax(root->left, depth + 1);
        }
        if (root->right)
        {
            findLeftMax(root->right, depth + 1);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        if (!root)
            return 0;
        maxDepth = 1;
        result = root->val;
        findLeftMax(root, maxDepth);
        return result;
    }
};
// @lc code=end

