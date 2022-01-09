#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapNodes(ListNode* root) {
        if (root == NULL or root->next == NULL) {
            return root;
        }

        ListNode* temp = swapNodes(root->next->next);
        ListNode* second = root->next;
        second->next = root;
        root->next = temp;
        return second;
    }

    ListNode* swapPairs(ListNode* head) {
        return swapNodes(head);
    }
};
// @lc code=end
