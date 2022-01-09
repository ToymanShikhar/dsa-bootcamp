#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=828 lang=cpp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */

// @lc code=start
class Solution {
   public:
    int uniqueLetterString(string s) {
        int n = s.length();
        int last[26][2];
        memset(last, -1, sizeof(last));

        int res = 0;

        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'A';

            res = res + (last[ch][1] - last[ch][0]) * (i - last[ch][1]);

            last[ch][0] = last[ch][1];
            last[ch][1] = i;
        }

        for (int i = 0; i < 26; i++) {
            res = res + (last[i][1] - last[i][0]) * (n - last[i][1]);
        }

        return res;
    }
};
// @lc code=end
