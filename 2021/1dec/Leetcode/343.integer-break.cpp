#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
   public:
    int findProd(int n, int sum, int dp[60]) {
        if (sum <= 1) {
            return 1;
        }

        if (dp[sum] != -1) {
            return dp[sum];
        }

        int ans = INT_MIN;
        for (int i = 1; i < (sum == n ? sum : sum + 1); i++) {
            int tempAns = i * findProd(n, sum - i, dp);
            ans = max(ans, tempAns);
        }

        return dp[sum] = ans;
    }

    int integerBreak(int n) {
        int dp[60];
        memset(dp, -1, sizeof(dp));
        return findProd(n, n, dp);
    }
};
// @lc code=end
