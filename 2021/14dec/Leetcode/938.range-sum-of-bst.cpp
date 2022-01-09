#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    int findSum(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return 0;
        }

        int ans = 0;
        if (root->val >= low and root->val <= high) {
            ans += root->val;
        }
        if (root->val >= low) {
            ans += findSum(root->left, low, high);
        }
        if (root->val <= high) {
            ans += findSum(root->right, low, high);
        }

        return ans;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return findSum(root, low, high);
    }
};
// @lc code=end
