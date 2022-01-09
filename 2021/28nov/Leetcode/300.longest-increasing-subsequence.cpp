#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        int dp[n + 1];
        int res = INT_MIN;
        for (int i = 0; i <= n; i++) {
            dp[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                res = max(res, dp[i]);
            }
        }

        return res;
    }
};
// @lc code=end
