#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    class compareList {
       public:
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* ans = res;

        priority_queue<ListNode*, vector<ListNode*>, compareList> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty()) {
            ListNode* t = pq.top();
            pq.pop();

            if (t->next != NULL) {
                pq.push(t->next);
            }

            ans->next = t;
            ans = ans->next;
        }

        return res->next;
    }
};
// @lc code=end
