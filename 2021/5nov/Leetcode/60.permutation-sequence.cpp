#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
   public:
    string getPermutation(int n, int k) {
        string res;

        int fact = 1;
        vector<int> nums;

        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k--;

        n--;

        while (n > 0) {
            int first = k / fact;

            res += to_string(nums[first]);
            nums.erase(nums.begin() + first);

            if (nums.size() == 1) {
                break;
            }

            k = k % fact;

            fact = fact / n;
            n--;
        }

        res += to_string(nums[0]);

        return res;
    }
};
// @lc code=end
