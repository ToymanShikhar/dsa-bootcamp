#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
   public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }
        double num = log10(n) / (double)log10(3);
        if (ceil(num) == floor(num)) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end
