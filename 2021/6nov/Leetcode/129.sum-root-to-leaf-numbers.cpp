#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    void traverse(TreeNode* root, int& sum, string& nums) {
        if (root == NULL) {
            return;
        }
        nums += to_string(root->val);
        if (root->left == NULL and root->right == NULL) {
            stringstream ss(nums);
            int n;
            ss >> n;
            sum += n;
        }

        traverse(root->left, sum, nums);
        traverse(root->right, sum, nums);

        nums.pop_back();
        return;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string nums;

        traverse(root, sum, nums);

        return sum;
    }
};
// @lc code=end
