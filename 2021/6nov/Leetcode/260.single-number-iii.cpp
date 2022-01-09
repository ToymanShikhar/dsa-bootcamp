#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
        }

        int i = 0;
        while (true) {
            int bt = (xr >> i) & 1;
            if (bt == 1) {
                break;
            }
            i++;
        }

        int one = 0;
        for (int j = 0; j < n; j++) {
            int bt = nums[j] >> i;
            if (bt & 1) {
                one ^= nums[j];
            }
        }

        int two = xr ^ one;

        vector<int> res;
        res.push_back(one);
        res.push_back(two);

        return res;
    }
};
// @lc code=end
