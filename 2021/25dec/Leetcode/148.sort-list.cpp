#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        while (l1 != NULL and l2 != NULL) {
            if (l1->val < l2->val) {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            } else {
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
        }
        while (l1 != NULL) {
            res->next = l1;
            res = res->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            res->next = l2;
            res = res->next;
            l2 = l2->next;
        }
        return ans->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }

        // Finding Mid Point
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL and fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tempNode = slow->next;
        slow->next = NULL;
        ListNode* l2 = mergeSort(tempNode);
        ListNode* l1 = mergeSort(head);

        return mergeList(l1, l2);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
// @lc code=end
