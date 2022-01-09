#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode;
        ListNode* res = dummy;

        while (head != NULL) {
            if (head->val != val) {
                res->next = head;
                res = res->next;
            }
            head = head->next;
        }
        res->next = NULL;
        return dummy->next;
    }
};
// @lc code=end
