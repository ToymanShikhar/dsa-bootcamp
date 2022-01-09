#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
   public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            solve(nums, i + 1, res);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        solve(nums, 0, res);

        return res;
    }
};
// @lc code=end
