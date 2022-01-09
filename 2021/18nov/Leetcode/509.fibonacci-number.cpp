#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
   public:
    int nthFib(int n, int dp[31]) {
        if (n <= 1) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int one = nthFib(n - 1, dp);
        int two = nthFib(n - 2, dp);

        return dp[n] = one + two;
    }

    int fib(int n) {
        int dp[31];
        memset(dp, -1, sizeof(dp));
        return nthFib(n, dp);
    }
};
// @lc code=end
