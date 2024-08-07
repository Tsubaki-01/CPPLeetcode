#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    struct ListNode* next;
};


class Solution {
public:
    /**
     * 判断是否为回文链表
     * @param head ListNode类 链表头
     * @return bool布尔型
     */
    bool isPalindrome(ListNode* head) {
        // write code here
        if (head == nullptr || head->next == nullptr)
            return true;

        int len = 0;
        // ListNode* vHead = new ListNode();
        // vHead->next = head;
        ListNode* cur = head;
        vector<int> vec;
        while (cur != nullptr)
        {
            len++;
            vec.push_back(cur->val);
            cur = cur->next;
        }

        for (auto i : vec)
            cout << i;

        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int i = 0;i < dp.size();++i)
            dp[i][i] = true;

        for (int i = dp.size() - 1;i >= 0;--i)
            for (int j = i + 1;j < dp.size();++j)
                if (vec[i] == vec[j])
                    dp[i][j] = dp[i + 1][j - 1];

        return dp[0][dp[0].size() - 1];


    }
};