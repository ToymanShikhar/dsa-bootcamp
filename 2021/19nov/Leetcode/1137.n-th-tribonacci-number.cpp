#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
   public:
    int nthFib(int n, int dp[38]) {
        if (n <= 1) {
            return n;
        }
        if (n == 2) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int one = nthFib(n - 1, dp);
        int two = nthFib(n - 2, dp);
        int three = nthFib(n - 3, dp);

        return dp[n] = one + two + three;
    }
    int tribonacci(int n) {
        int dp[38];
        memset(dp, -1, sizeof(dp));
        return nthFib(n, dp);
    }
};
// @lc code=end
