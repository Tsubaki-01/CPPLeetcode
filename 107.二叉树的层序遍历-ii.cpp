/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> result;
        queue<TreeNode*>  que;
        if (root != nullptr) que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            vector<int> tmp;
            for (int i = 0;i < size;i++)
            {
                tmp.push_back(que.front()->val);
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);
                que.pop();

            }
            result.push_back(tmp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// @lc code=end

