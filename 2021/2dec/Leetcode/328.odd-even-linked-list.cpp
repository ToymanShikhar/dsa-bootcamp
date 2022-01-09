#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* oddTemp = odd;
        ListNode* even = new ListNode(0);
        ListNode* evenTemp = even;

        ListNode* temp = head;
        int flag = 0;
        while (temp != NULL) {
            if (flag == 0) {
                oddTemp->next = temp;
                temp = temp->next;
                oddTemp = oddTemp->next;
                flag = 1;
            } else {
                evenTemp->next = temp;
                temp = temp->next;
                evenTemp = evenTemp->next;
                flag = 0;
            }
        }

        oddTemp->next = even->next;
        evenTemp->next = NULL;
        return odd->next;
    }
};
// @lc code=end
