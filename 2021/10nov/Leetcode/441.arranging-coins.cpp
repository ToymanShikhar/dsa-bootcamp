#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
   public:
    int arrangeCoins(int n) {
        int res = 0;
        long long sum = 0;
        int num = 1;

        while (sum <= (long long)n) {
            res++;
            sum += num;
            num++;
        }

        return res - 1;
    }
};
// @lc code=end
