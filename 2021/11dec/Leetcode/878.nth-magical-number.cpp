#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 */

// @lc code=start
class Solution {
   public:
    int findGCD(int a, int b) {
        if (a == 0) {
            return b;
        }
        return findGCD(b % a, a);
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long left = min(a, b);
        long long right = n * left;

        long long gcd = (long long)findGCD(min(a, b), a + b - min(a, b));
        long long lcm = a * b / gcd;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long x = mid / a + mid / b - mid / lcm;

            if (x < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return (int)(left % 1000000007);
    }
};
// @lc code=end
