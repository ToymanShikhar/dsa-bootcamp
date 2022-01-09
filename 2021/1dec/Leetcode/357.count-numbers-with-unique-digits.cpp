#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
   public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                ans += 10;
            } else {
                int temp = 9;
                for (int j = 9, k = 2; k <= i; k++, j--) {
                    temp *= j;
                }
                ans += temp;
            }
        }

        return ans;
    }
};
// @lc code=end
