#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    pair<int, int> solve(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        pair<int, int> lt = solve(root->left);
        pair<int, int> right = solve(root->right);
        int tilt = abs(lt.second - right.second);
        return {lt.first + right.first + tilt, lt.second + right.second + root->val};
    }

    int findTilt(TreeNode* root) {
        pair<int, int> ans = solve(root);
        return ans.first;
    }
};
// @lc code=end
