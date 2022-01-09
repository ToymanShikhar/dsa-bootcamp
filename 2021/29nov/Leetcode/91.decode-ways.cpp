#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
   public:
    int findWays(string s, int n, int curr, int dp[101]) {
        if (curr >= n) {
            return 1;
        }

        if (s[curr] == '0') {
            return 0;
        }

        if (dp[curr] != -1) {
            return dp[curr];
        }

        int one = findWays(s, n, curr + 1, dp);
        int two = 0;
        if (curr < n - 1) {
            int num = s[curr] - '1' + 1;
            num = num * 10;
            int num1 = s[curr + 1] - '1' + 1;
            num += num1;

            if (num <= 26) {
                two = findWays(s, n, curr + 2, dp);
            }
        }

        return dp[curr] = one + two;
    }

    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0') {
            return 0;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                if (s[i - 1] != '1' and s[i - 1] != '2') {
                    return 0;
                }
            }
        }

        int dp[101];
        memset(dp, -1, sizeof(dp));

        return findWays(s, n, 0, dp);
    }
};
// @lc code=end
