/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    struct cmp
    {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        int len = lists.size();

        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        priority_queue < ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0;i < len;i++)
        {
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }

        while (!pq.empty())
        {
            ListNode* t = pq.top();
            pq.pop();
            tail->next = t;
            tail = tail->next;
            if (t->next != nullptr)
                pq.push(t->next);
        }
        return dummyHead->next;
    }
};
// @lc code=end

/* class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        int len = lists.size();

        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        while (true)
        {
            ListNode* minNode;
            int curMin = INT_MAX;
            int minI = -1;
            for (int i = 0;i < len;i++)
            {
                if (lists[i] == nullptr)
                    continue;
                else {
                    if (lists[i]->val < curMin)
                    {
                        curMin = lists[i]->val;
                        minNode = lists[i];
                        minI = i;
                    }
                }
            }
            if (minI == -1)
                break;
            tail->next = minNode;
            tail = tail->next;
            lists[minI] = minNode->next;
        }
        return dummyHead->next;
    }
}; */