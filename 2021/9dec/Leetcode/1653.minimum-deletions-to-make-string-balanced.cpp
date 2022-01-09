#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
class Solution {
   public:
    int minimumDeletions(string s) {
        int a = 0;
        int b = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                a++;
            } else {
                b = max(a + 1, b + 1);
            }
        }

        return s.length() - max(a, b);
    }
};
// @lc code=end
