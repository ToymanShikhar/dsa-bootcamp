#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
   public:
    int maxMoney(vector<int>& nums, int curr, int dp[101]) {
        if (curr >= nums.size()) {
            return 0;
        }

        if (dp[curr] != -1) {
            return dp[curr];
        }

        int rob = nums[curr] + maxMoney(nums, curr + 2, dp);
        int notRob = maxMoney(nums, curr + 1, dp);

        return dp[curr] = max(rob, notRob);
    }

    int rob(vector<int>& nums) {
        int dp[101];
        memset(dp, -1, sizeof(dp));
        return maxMoney(nums, 0, dp);
    }
};
// @lc code=end
