#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
   public:
    int findLongest(string one, string two, int e1, int e2, int dp[1001][1001]) {
        if (e1 == 0 or e2 == 0) {
            return 0;
        }

        if (dp[e1][e2] != -1) {
            return dp[e1][e2];
        }

        int ans;
        if (one[e1 - 1] == two[e2 - 1]) {
            return 1 + findLongest(one, two, e1 - 1, e2 - 1, dp);
        } else {
            int op1 = findLongest(one, two, e1 - 1, e2, dp);
            int op2 = findLongest(one, two, e1, e2 - 1, dp);
            return dp[e1][e2] = max(op1, op2);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        int dp[n1 + 1][n2 + 1];

        for (int i = 0; i <= n1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n2; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};
// @lc code=end
