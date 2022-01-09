#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }

        int dp[n + 1][2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = 1;
            }
        }

        int ans = 1;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                if (diff < 0) {
                    dp[j][0] = max(dp[j][0], dp[i][1] + 1);
                    ans = max(ans, dp[j][0]);
                } else if (diff > 0) {
                    dp[j][1] = max(dp[j][1], dp[i][0] + 1);
                    ans = max(ans, dp[j][1]);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
