/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

 // @lc code=start
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>  que;
        if (root != nullptr) que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            Node* tmp;
            for (int i = 0;i < size;i++)
            {
                tmp = que.front();
                que.pop();
                if (i == size - 1) tmp->next = nullptr;
                else tmp->next = que.front();
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);

            }
        }
        return root;
    }
};
// @lc code=end

