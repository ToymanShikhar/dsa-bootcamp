/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* A) {
        if (A == NULL) {
            return NULL;
        }
        if (A->next == NULL) {
            return A;
        }

        ListNode* temp = A;
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;

        int cnt = 1;
        int num = A->val;
        ListNode* prev = temp;
        temp = temp->next;

        while (temp != NULL) {
            if (temp->val == num) {
                cnt++;

            } else if (temp->val != num and cnt == 1) {
                res->next = prev;
                res = res->next;
                cnt = 1;
                num = temp->val;

            } else {
                cnt = 1;
                num = temp->val;
            }
            prev = temp;
            temp = temp->next;
        }
        if (cnt == 1) {
            res->next = prev;
        } else {
            res->next = NULL;
        }

        return dummy->next;
    }
};
// @lc code=end
