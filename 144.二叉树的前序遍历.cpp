// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem144.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        if (root != nullptr) st.push(root);
        while (!st.empty())
        {
            cur = st.top();
            if (cur != nullptr)
            {
                st.pop();
                if (cur->right != nullptr) st.push(cur->right);
                if (cur->left != nullptr)st.push(cur->left);
                st.push(cur);
                st.push(nullptr);
            }
            else
            {
                st.pop();
                result.push_back(st.top()->val);
                st.pop();
            }
        }

        return result;
    }
};
// @lc code=end

