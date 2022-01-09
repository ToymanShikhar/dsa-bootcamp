#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
   public:
    double findWays(int n, int k, int i, int j, double dp[26][26][101]) {
        if (i < 0 or i >= n or j < 0 or j >= n) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }

        if (dp[i][j][k] != -1.0) {
            return dp[i][j][k];
        }

        double ans = 0;

        ans += findWays(n, k - 1, i - 1, j + 2, dp);
        ans += findWays(n, k - 1, i - 2, j + 1, dp);
        ans += findWays(n, k - 1, i - 2, j - 1, dp);
        ans += findWays(n, k - 1, i - 1, j - 2, dp);
        ans += findWays(n, k - 1, i + 1, j + 2, dp);
        ans += findWays(n, k - 1, i + 2, j + 1, dp);
        ans += findWays(n, k - 1, i + 2, j - 1, dp);
        ans += findWays(n, k - 1, i + 1, j - 2, dp);

        ans = ans / 8.0;

        return dp[i][j][k] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        double dp[26][26][101];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 101; k++) {
                    dp[i][j][k] = -1.0;
                }
            }
        }

        return findWays(n, k, row, column, dp);
    }
};
// @lc code=end
