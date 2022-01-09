#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int maxCost(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (root == NULL) {
            return 0;
        }

        if (m.count(root)) {
            return m[root];
        }

        int consider = root->val;
        if (root->left != NULL) {
            consider += maxCost(root->left->left, m);
            consider += maxCost(root->left->right, m);
        }
        if (root->right != NULL) {
            consider += maxCost(root->right->left, m);
            consider += maxCost(root->right->right, m);
        }

        int notConsider = maxCost(root->left, m) + maxCost(root->right, m);

        return m[root] = max(consider, notConsider);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return maxCost(root, m);
    }
};
// @lc code=end
