/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

 // @lc code=start

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;

        for (int i = 0;i < n;i++)
        {
            fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return dummyHead->next;

    }
};
// @lc code=end

