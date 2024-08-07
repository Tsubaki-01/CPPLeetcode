/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*>  que;
        if (root != nullptr) que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            vector<int> tmp;
            for (int i = 0;i < size;i++)
            {
                tmp.push_back(que.front()->val);
                for (int j = 0;j < que.front()->children.size();j++)
                    if (que.front()->children[j]) que.push(que.front()->children[j]);
                que.pop();

            }
            result.push_back(tmp);
        }
        return result;
    }
};
// @lc code=end

