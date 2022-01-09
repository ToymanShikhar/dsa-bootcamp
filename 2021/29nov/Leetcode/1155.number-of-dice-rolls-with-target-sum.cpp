#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution {
   public:
    int findWays(int d, int f, int t, int dp[31][1001]) {
        if (d == 0) {
            if (t == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[d][t] != -1) {
            return dp[d][t];
        }

        int ans = 0;
        for (int i = 1; i <= f; i++) {
            if (i <= t) {
                int tempAns = findWays(d - 1, f, t - i, dp);
                ans = ((ans % 1000000007) + (tempAns % 1000000007)) % 1000000007;
            }
        }

        return dp[d][t] = ans % 1000000007;
    }
    int numRollsToTarget(int d, int f, int target) {
        int dp[31][1001];
        memset(dp, -1, sizeof(dp));
        return findWays(d, f, target, dp) % 1000000007;
    }
};
// @lc code=end
