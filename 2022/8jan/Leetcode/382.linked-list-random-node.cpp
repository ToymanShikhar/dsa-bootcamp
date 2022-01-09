#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
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
    ListNode* root;
    Solution(ListNode* head) {
        root = head;
    }

    int getRandom() {
        ListNode* curr = root;
        int res = -1;
        int len = 1;
        while (curr != NULL) {
            int ran = rand() % len;
            if (ran == len - 1) {
                res = curr->val;
            }

            len++;
            curr = curr->next;
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
