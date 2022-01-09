#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
   public:
    static bool compare(int a, int b) {
        string n1 = to_string(a) + to_string(b);
        string n2 = to_string(b) + to_string(a);

        if (n1 < n2) {
            return true;
        } else {
            return false;
        }
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string ans;

        for (int i = nums.size() - 1; i >= 0; i--) {
            ans += to_string(nums[i]);
        }

        int countZeros = 0;
        for (auto x : ans) {
            if (x == '0') {
                countZeros++;
            }
        }
        if (countZeros == ans.length()) {
            return "0";
        }

        return ans;
    }
};
// @lc code=end
