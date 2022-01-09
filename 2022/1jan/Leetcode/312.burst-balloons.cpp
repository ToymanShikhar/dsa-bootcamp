#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
   public:
    int solve(vector<int>& nums, int i, int j, int dp[510][510]) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        for (int k = i; k <= j; k++) {
            int tempAns = solve(nums, i, k - 1, dp) + solve(nums, k + 1, j, dp);
            tempAns += nums[k] * nums[i - 1] * nums[j + 1];

            ans = max(ans, tempAns);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int dp[510][510];
        memset(dp, -1, sizeof(dp));

        return solve(nums, 1, nums.size() - 2, dp);
    }
};
// @lc code=end
