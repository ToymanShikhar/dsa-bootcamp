#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    pair<int, int> maxSum(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        pair<int, int> left = maxSum(root->left);
        pair<int, int> right = maxSum(root->right);

        int op1 = left.first + right.first + root->val;
        int op2 = left.first + root->val;
        int op3 = right.first + root->val;
        int op4 = max(op2, max(op3, root->val));

        pair<int, int> ans;
        ans.first = max(left.first, right.first) + root->val;
        ans.first = max(ans.first, root->val);

        if (root->left == NULL and root->right == NULL) {
            ans.second = root->val;
        } else if (root->left != NULL and root->right == NULL) {
            ans.second = max(op1, max(left.second, root->val));
        } else if (root->left == NULL and root->right != NULL) {
            ans.second = max(op1, max(right.second, root->val));
        } else
            ans.second = max(op1, max(left.second, max(right.second, op4)));

        return ans;
    }

    int maxPathSum(TreeNode* root) {
        pair<int, int> ans = maxSum(root);
        return ans.second;
    }
};
// @lc code=end
