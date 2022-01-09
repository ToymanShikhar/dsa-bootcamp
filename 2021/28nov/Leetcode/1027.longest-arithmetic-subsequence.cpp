#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
   public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 1][2001];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 2000; j++) {
                dp[i][j] = 1;
            }
        }
        int res = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = nums[j] - nums[i] + 1000;
                dp[j][d] = dp[i][d] + 1;
                res = max(res, dp[j][d]);
            }
        }

        return res;
    }
};
// @lc code=end
