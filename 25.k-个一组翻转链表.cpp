// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem25.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
#include <string>
#include<algorithm>
#include<vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


/* struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}; */
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

    void reverse(ListNode* head, ListNode* tail)
    {
        ListNode* pre = tail->next;
        ListNode* cur = head;

        while (pre != tail)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* tail = dummyHead;
        ListNode* pre = tail;

        while (head != nullptr)
        {
            for (int i = 0;i < k;i++)
            {
                tail = tail->next;
                if (tail == nullptr)
                    return dummyHead->next;
            }
            reverse(head, tail);
            pre->next = tail;
            pre = head;
            tail = head;
            head = head->next;
        }

        return dummyHead->next;
    }
};
// @lc code=end
