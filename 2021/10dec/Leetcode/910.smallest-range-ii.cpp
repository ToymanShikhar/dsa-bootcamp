#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=910 lang=cpp
 *
 * [910] Smallest Range II
 */

// @lc code=start
class Solution {
   public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = nums[n - 1] - nums[0];
        for (int i = 0; i < n - 1; i++) {
            int mini = min(nums[0] + k, nums[i + 1] - k);
            int maxi = max(nums[n - 1] - k, nums[i] + k);
            res = min(res, maxi - mini);
        }

        return res;
    }
};
// @lc code=end
