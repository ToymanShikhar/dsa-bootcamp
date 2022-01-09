#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
   public:
    int minCost(string w1, string w2, int i, int j, int dp[501][501]) {
        if (j >= w2.length()) {
            return w1.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;
        int ins = 1 + minCost(w1, w2, i, j + 1, dp);
        ans = min(ans, ins);
        if (i < w1.length()) {
            int del = 1 + minCost(w1, w2, i + 1, j, dp);
            ans = min(ans, del);

            if (w1[i] == w2[j]) {
                int rep1 = minCost(w1, w2, i + 1, j + 1, dp);
                ans = min(ans, rep1);
            }
            int rep2 = 1 + minCost(w1, w2, i + 1, j + 1, dp);
            ans = min(ans, rep2);
        }

        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        int dp[501][501];
        memset(dp, -1, sizeof(dp));
        return minCost(word1, word2, 0, 0, dp);
    }
};
// @lc code=end
