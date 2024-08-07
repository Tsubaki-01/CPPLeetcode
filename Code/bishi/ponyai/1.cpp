#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    int inCnt;
    int outCnt;
    vector<Node*> inNode;
    vector<Node*> outNode;
    Node(int v) :val(v) {};
};

bool IsBinaryTree(int n, const std::vector<std::pair<int, int>>& edges)
{
    unordered_map<int, Node*> map;
    int nodeCnt = 0;
    for (auto v : edges)
    {
        if (map.count(v.first) == 0)
        {
            Node* nodeOut = new Node(v.first);
            map[v.first] = nodeOut;
            nodeCnt++;
        }
        if (map.count(v.second) == 0)
        {
            Node* nodeIn = new Node(v.second);
            map[v.second] = nodeIn;
            nodeCnt++;
        }
        map[v.first]->outCnt++;
        map[v.second]->inCnt++;
        map[v.first]->outNode.push_back(map[v.second]);
        map[v.second]->inNode.push_back(map[v.first]);
    }
    Node* root;
    int flag = 1;
    for (auto node : map)
    {
        if (node.second->inCnt == 0)
            if (flag)
            {
                root = node.second;
                flag = 0;
            }
            else return false;
        if (node.second->inCnt > 1) return false;
        if (node.second->outCnt > 2) return false;
    }

    int t = 0;
    vector<Node*> visited;
    queue<Node*> que;
    que.push(root);
    visited.push_back(root);
    t++;

    while (!que.empty())
    {
        auto curNode = que.front();
        que.pop();
        for (auto& item : curNode->outNode)
        {
            if (find(visited.begin(), visited.end(), item) != visited.end())
                continue;
            que.push(item);
            visited.push_back(item);
            t++;
        }
    }

    if (t == nodeCnt) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    int x;
    int y;
    while (cin >> x >> y)
    {
        edges.emplace_back(x, y);
    }
    cout << IsBinaryTree(n, edges);
    return 0;
}