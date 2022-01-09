#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int minCuts(string& s, int start, int end, int dp[2001][2001]) {
        if (isPalindrome(s, start, end)) {
            return 0;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int ans = INT_MAX / 2;
        for (int i = start; i < end; i++) {
            if (isPalindrome(s, start, i)) {
                int left = minCuts(s, start, i, dp);
                int right = right = minCuts(s, i + 1, end, dp);
                ans = min(ans, 1 + left + right);
            }
        }

        return dp[start][end] = ans;
    }

    int minCut(string s) {
        int dp[2001][2001];
        memset(dp, -1, sizeof(dp));
        return minCuts(s, 0, s.length() - 1, dp);
    }
};
// @lc code=end
