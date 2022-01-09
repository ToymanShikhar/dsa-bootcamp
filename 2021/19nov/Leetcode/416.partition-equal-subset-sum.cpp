#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
   public:
    bool isPossible(vector<int>& nums, int curr, int sum, int dp[][201]) {
        if (sum == 0) {
            return true;
        }
        if (curr >= nums.size()) {
            return false;
        }

        if (dp[sum][curr] != -1) {
            return dp[sum][curr];
        }

        bool consider = false;
        if (nums[curr] <= sum) {
            consider = isPossible(nums, curr + 1, sum - nums[curr], dp);
        }

        bool notConsider = isPossible(nums, curr + 1, sum, dp);

        return dp[sum][curr] = consider || notConsider;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }

        if (sum % 2 != 0) {
            return false;
        }

        sum = sum / 2;
        int dp[sum + 1][201];
        memset(dp, -1, sizeof(dp));

        return isPossible(nums, 0, sum, dp);
    }
};
// @lc code=end
