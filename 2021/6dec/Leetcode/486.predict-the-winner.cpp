#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
   public:
    int maxScore(vector<int>& nums, int i, int j, vector<int>& sums, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int start = maxScore(nums, i + 1, j, sums, dp);
        int end = maxScore(nums, i, j - 1, sums, dp);

        int ans = min(start, end);

        return dp[i][j] = sums[j] - sums[i] + nums[i] - ans;
    }

    bool PredictTheWinner(vector<int>& nums) {
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sums[i] = sums[i - 1] + nums[i];
        }

        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        double score = (double)maxScore(nums, 0, nums.size() - 1, sums, dp);

        if (score >= (double)(sums[nums.size() - 1] / 2.0)) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end
