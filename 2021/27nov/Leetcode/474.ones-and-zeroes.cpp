#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
   public:
    int maxSize(vector<string>& strs, int curr, int m, int n, int dp[601][101][101]) {
        if (curr >= strs.size()) {
            return 0;
        }

        if (dp[curr][m][n] != -1) {
            return dp[curr][m][n];
        }

        int zeros = 0;
        int ones = 0;
        for (auto x : strs[curr]) {
            if (x == '1') {
                ones++;
            } else {
                zeros++;
            }
        }

        int consider = 0;
        if (zeros <= m and ones <= n) {
            consider = 1 + maxSize(strs, curr + 1, m - zeros, n - ones, dp);
        }

        int notConsider = maxSize(strs, curr + 1, m, n, dp);

        return dp[curr][m][n] = max(consider, notConsider);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[601][101][101];
        memset(dp, -1, sizeof(dp));
        return maxSize(strs, 0, m, n, dp);
    }
};
// @lc code=end
