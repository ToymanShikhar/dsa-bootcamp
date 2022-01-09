#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
   public:
    int numTrees(int n) {
        int dp[20]{0};
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int l = 0;
            int r = i - 1;

            while (l <= i - 1) {
                dp[i] += (dp[l] * dp[r]);
                l++;
                r--;
            }
        }

        return dp[n];
    }
};
// @lc code=end
