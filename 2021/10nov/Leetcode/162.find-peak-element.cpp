#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int mid = (s + e) / 2;

            if ((mid - 1 < 0 ? true : nums[mid - 1] < nums[mid]) and (mid + 1 >= n ? false : nums[mid + 1] > nums[mid])) {
                s = mid + 1;
            } else if ((mid - 1 < 0 ? false : nums[mid - 1] > nums[mid]) and (mid + 1 >= n ? true : nums[mid + 1] < nums[mid])) {
                e = mid - 1;
            } else if ((mid - 1 < 0 ? true : nums[mid - 1] < nums[mid]) and (mid + 1 >= n ? true : nums[mid + 1] < nums[mid])) {
                return mid;
            } else {
                e = mid - 1;
            }
        }

        return 0;
    }
};
// @lc code=end
