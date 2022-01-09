#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        // Max Product will either start from left end i.e., i=0
        // or from right end i.e., i=n-1
        // Handle case for zero otherwise

        int n = nums.size();

        int left = nums[0];
        int righ = nums[n - 1];
        int currLeft = left;
        int currRigh = righ;

        for (int i = 1; i < n; i++) {
            if (currLeft == 0) {
                currLeft = 1;
            }
            currLeft *= nums[i];
            left = max(left, currLeft);
        }

        for (int i = n - 2; i >= 0; i--) {
            if (currRigh == 0) {
                currRigh = 1;
            }
            currRigh *= nums[i];
            righ = max(righ, currRigh);
        }

        return max(left, righ);
    }
};
// @lc code=end
