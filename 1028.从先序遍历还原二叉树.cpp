/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] 从先序遍历还原二叉树
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
    TreeNode* buildTree(string& s, int& pos, int depth)
    {
        if (pos == s.size())
            return nullptr;

        int cnt = 0;
        int tmp = pos;
        while (s[tmp] == '-')
        {
            cnt++;
            tmp++;
        }


        if (cnt == depth)
        {
            int val = 0;
            while ((tmp < s.size() && s[tmp] != '-'))
            {
                val = val * 10 + s[tmp] - '0';
                tmp++;
            }
            TreeNode* root = new TreeNode(val);
            pos = tmp;
            root->left = buildTree(s, pos, depth + 1);
            root->right = buildTree(s, pos, depth + 1);
            return root;
        }

        return nullptr;
    }


    TreeNode* recoverFromPreorder(string traversal) {
        int pos = 0;
        return buildTree(traversal, pos, 0);
    }
};
// @lc code=end

