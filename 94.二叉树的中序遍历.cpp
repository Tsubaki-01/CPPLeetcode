/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                st.push(cur);
                st.push(nullptr);
                if (cur->left != nullptr)st.push(cur->left);
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

