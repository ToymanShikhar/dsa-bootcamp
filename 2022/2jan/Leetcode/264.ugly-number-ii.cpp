#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
   public:
    int nthUglyNumber(int n) {
        int two = 0;
        int three = 0;
        int five = 0;

        vector<int> res(n, 1);
        int curr = 1;

        while (curr < n) {
            int least = min(2 * res[two], min(3 * res[three], 5 * res[five]));
            if (least == 2 * res[two]) two++;
            if (least == 3 * res[three]) three++;
            if (least == 5 * res[five]) five++;

            res[curr] = least;
            curr++;
        }

        return res[n - 1];
    }
};
// @lc code=end
