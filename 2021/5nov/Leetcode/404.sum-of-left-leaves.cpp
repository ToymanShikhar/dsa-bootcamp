#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    void traverse(TreeNode* root, int& sum) {
        if (root == NULL) {
            return;
        }

        if (root->left and root->left->left == NULL and root->left->right == NULL) {
            sum += root->left->val;
        }

        traverse(root->left, sum);
        traverse(root->right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;

        traverse(root, sum);

        return sum;
    }
};
// @lc code=end
