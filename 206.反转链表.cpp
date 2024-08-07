/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = head->next;

        while (next != nullptr)
        {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }

        cur->next = pre;

        return cur;

    }
};
// @lc code=end

