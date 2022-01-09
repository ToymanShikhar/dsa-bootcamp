#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    ListNode* reverseList(ListNode* root) {
        ListNode* prev = NULL;

        while (root != NULL) {
            ListNode* next = root->next;
            root->next = prev;
            prev = root;
            root = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* r = reverseList(slow->next);
        slow->next = NULL;

        ListNode* dummy = new ListNode(0);
        slow = head;
        head = dummy;
        while (slow != NULL) {
            dummy->next = slow;
            slow = slow->next;
            dummy = dummy->next;
            if (r) {
                dummy->next = r;
                dummy = dummy->next;
                r = r->next;
            }
        }

        head = head->next;
    }
};
// @lc code=end
