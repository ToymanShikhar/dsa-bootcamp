#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
   public:
    int numSquares(int n) {
        int num = floor(sqrt(n));
        vector<int> v(num);
        for (int i = 0; i < num; i++) {
            v[i] = (i + 1) * (i + 1);
        }

        int dp[num + 1][n + 1];
        for (int i = 0; i <= num; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            dp[0][i] = INT_MAX / 2;
        }
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= n; j++) {
                int consider = INT_MAX / 2;
                if (v[i - 1] <= j) {
                    consider = 1 + dp[i][j - v[i - 1]];
                }
                int notConsider = dp[i - 1][j];

                dp[i][j] = min(consider, notConsider);
            }
        }

        return dp[num][n];
    }
};
// @lc code=end
