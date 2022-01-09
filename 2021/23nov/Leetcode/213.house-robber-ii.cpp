#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
   public:
    int maxAmount(vector<int>& nums, int curr, bool first, int dp[101][2]) {
        if (curr >= nums.size()) {
            return 0;
        }

        if (dp[curr][first] != -1) {
            return dp[curr][first];
        }

        int rob;
        if (curr == 0) {
            rob = nums[curr] + maxAmount(nums, curr + 2, true, dp);
        } else {
            if (curr == nums.size() - 1 and first)
                rob = 0;
            else
                rob = nums[curr] + maxAmount(nums, curr + 2, first, dp);
        }

        int notRob = maxAmount(nums, curr + 1, first, dp);

        return dp[curr][first] = max(rob, notRob);
    }

    int rob(vector<int>& nums) {
        int dp[101][2];
        memset(dp, -1, sizeof(dp));
        return maxAmount(nums, 0, false, dp);
    }
};
// @lc code=end
