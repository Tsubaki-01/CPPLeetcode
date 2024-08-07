/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

 // @lc code=start

 //   Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int A_len = 0;
        int B_len = 0;
        ListNode* cnt;

        cnt = headA;
        while (cnt != nullptr)
        {
            A_len++;
            cnt = cnt->next;
        }
        cnt = headB;
        while (cnt != nullptr)
        {
            B_len++;
            cnt = cnt->next;
        }


        ListNode* A_ptr = headA;
        ListNode* B_ptr = headB;
        int dis = A_len - B_len;
        if (dis < 0)
        {
            swap(A_ptr, B_ptr);
            swap(A_len, B_len);
            dis = -dis;
        }
        while (dis--)
        {
            A_ptr = A_ptr->next;
        }

        while (A_ptr != nullptr && B_ptr != nullptr)
        {
            if (A_ptr == B_ptr)
            {
                return A_ptr;
            }
            A_ptr = A_ptr->next;
            B_ptr = B_ptr->next;
        }

        return A_ptr;

    }
};
// @lc code=end

