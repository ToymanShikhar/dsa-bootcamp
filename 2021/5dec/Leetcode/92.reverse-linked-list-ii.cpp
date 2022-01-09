/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverse(ListNode* root) {
        ListNode* prev = NULL;

        while (root != NULL) {
            ListNode* next = root->next;
            root->next = prev;
            prev = root;
            root = next;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* start = head;
        ListNode* end = head;

        for (int i = 1; i < right; i++) {
            if (i < left) {
                prev = start;
                start = start->next;
            }
            end = end->next;
        }

        ListNode* last = end->next;
        end->next = NULL;

        ListNode* reversed = reverse(start);
        prev->next = reversed;
        start->next = last;

        return dummy->next;
    }
};
// @lc code=end
