#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head != NULL) {
            ans = ans | (head->val);
            ans = ans << 1;
            head = head->next;
        }

        return ans >> 1;
    }
};
// @lc code=end
