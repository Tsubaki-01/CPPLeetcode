/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* pre = dummyHead;
        ListNode* cur = nullptr;
        int jinwei = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
            {
                int t = jinwei + l2->val;
                if (t >= 10)
                {
                    cur = new ListNode(t % 10);
                    jinwei = 1;
                }
                else {
                    cur = new ListNode(t);
                    jinwei = 0;
                }

                pre->next = cur;
                pre = cur;
                l2 = l2->next;
                continue;
            }
            if (l2 == nullptr)
            {
                int t = jinwei + l1->val;
                if (t >= 10)
                {
                    cur = new ListNode(t % 10);
                    jinwei = 1;
                }
                else {
                    cur = new ListNode(t);
                    jinwei = 0;
                }
                pre->next = cur;
                pre = cur;
                l1 = l1->next;
                continue;
            }

            int t = jinwei + l1->val + l2->val;
            if (t >= 10)
            {
                cur = new ListNode(t % 10);
                jinwei = 1;
            }
            else {
                cur = new ListNode(t);
                jinwei = 0;
            }
            pre->next = cur;
            pre = cur;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (jinwei == 1)
            pre->next = new ListNode(1);

        return dummyHead->next;
    }
};
// @lc code=end

