#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
   public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
        }

        unordered_set<int> st;

        for (int j = i; j < nums.size(); j++) {
            if (st.find(nums[j]) != st.end()) {
                continue;
            }
            st.insert(nums[j]);
            swap(nums[i], nums[j]);
            solve(nums, i + 1, res);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        solve(nums, 0, res);

        return res;
    }
};
// @lc code=end
