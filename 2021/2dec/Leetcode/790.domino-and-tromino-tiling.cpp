#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
   public:
    int totalWays(int n, int dp[1001]) {
        if (n == 0) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int one = totalWays(n - 1, dp) % 1000000007;
        if (n >= 2) {
            one = (one % 1000000007 + totalWays(n - 2, dp) % 1000000007) % 1000000007;
        }
        int i = 3;
        while (i <= n) {
            one = (one % 1000000007 + ((2 * (totalWays(n - i, dp) % 1000000007)) % 1000000007) % 1000000007) % 1000000007;
            i++;
        }

        return dp[n] = one % 1000000007;
    }

    int numTilings(int n) {
        int dp[1001];
        memset(dp, -1, sizeof(dp));
        return totalWays(n, dp) % 1000000007;
    }
};
// @lc code=end