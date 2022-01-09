#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
   public:
    bool matches(string s, int i, string s1) {
        int j = 0;

        while (i < s.length() and j < s1.length()) {
            if (s[i] != s1[j]) {
                return false;
            }
            i++;
            j++;
        }
        if (j == s1.length()) {
            return true;
        }

        return false;
    }

    bool check(string& s, int i, vector<string>& dict, int dp[301]) {
        if (i == s.length()) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        bool ans = false;
        for (int j = 0; j < dict.size(); j++) {
            if (matches(s, i, dict[j])) {
                bool ans2 = check(s, i + dict[j].length(), dict, dp);
                ans = ans or ans2;
            }
        }

        return dp[i] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[301];
        memset(dp, -1, sizeof(dp));

        return check(s, 0, wordDict, dp);
    }
};
// @lc code=end
