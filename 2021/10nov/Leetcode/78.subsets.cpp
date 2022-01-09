#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> res;
    void dfs(int i, vector<int>& nums, vector<int>& temp) {
        res.push_back(temp);

        if (i == nums.size()) {
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            temp.push_back(nums[j]);
            dfs(j + 1, nums, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(0, nums, temp);
        return res;
    }
};
// @lc code=end
