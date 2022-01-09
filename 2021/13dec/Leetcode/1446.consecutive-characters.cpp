#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
class Solution {
   public:
    int maxPower(string s) {
        int count = 1;
        int res = count;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                res = max(res, count);
                count = 1;
            }
        }
        res = max(res, count);
        return res;
    }
};
// @lc code=end
