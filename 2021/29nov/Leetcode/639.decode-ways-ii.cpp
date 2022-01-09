#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 */

// @lc code=start
class Solution {
   public:
    long long findWays(string& s, int n, int curr, long long dp[100001]) {
        if (curr >= n) {
            return 1;
        }

        if (s[curr] == '0') {
            return 0;
        }

        if (dp[curr] != -1) {
            return dp[curr];
        }

        long long one = findWays(s, n, curr + 1, dp);
        if (s[curr] == '*') {
            one *= 9;
        }

        long long two = 0;
        if (curr < n - 1) {
            if (s[curr] == '*' and s[curr + 1] == '*') {
                two = 15 * findWays(s, n, curr + 2, dp);
            } else if (s[curr] == '*' and s[curr + 1] != '*') {
                if ((s[curr + 1] - '1' + 1) <= 6) {
                    two = 2 * findWays(s, n, curr + 2, dp);
                } else {
                    two = findWays(s, n, curr + 2, dp);
                }
            } else if (s[curr] != '*' and s[curr + 1] == '*') {
                if (s[curr] == '1') {
                    two = 9 * findWays(s, n, curr + 2, dp);
                } else if (s[curr] == '2') {
                    two = 6 * findWays(s, n, curr + 2, dp);
                }
            } else {
                int num = s[curr] - '1' + 1;
                num = num * 10;
                int num1 = s[curr + 1] - '1' + 1;
                num += num1;

                if (num <= 26) {
                    two = findWays(s, n, curr + 2, dp);
                }
            }
        }

        one = one % 1000000007;
        two = two % 1000000007;

        return dp[curr] = (one + two) % 1000000007;
    }

    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0') {
            return 0;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                if (s[i - 1] != '1' and s[i - 1] != '2' and s[i - 1] != '*') {
                    return 0;
                }
            }
        }

        long long dp[100001];
        memset(dp, -1, sizeof(dp));

        long long ans = findWays(s, n, 0, dp) % 1000000007;
        return (int)ans;
    }
};
// @lc code=end
