#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
   public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }

        int s = 0;
        int e = nums.size() - 1;
        int mn = INT_MAX;

        while (s <= e) {
            int mid = (s + e) / 2;
            mn = min(mn, nums[mid]);
            if (nums[mid] >= nums[0]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return mn;
    }
};
// @lc code=end
