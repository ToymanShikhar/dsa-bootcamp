#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */

// @lc code=start
class Solution {
   public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (auto x : arr) {
            int rem = ((x % k) + k) % k;
            int numToFind = rem != 0 ? k - rem : 0;

            if (m.count(numToFind)) {
                m[numToFind]--;
                if (m[numToFind] == 0) {
                    m.erase(numToFind);
                }
            } else {
                m[rem]++;
            }
        }

        if (m.size() == 0) {
            return true;
        }
        return false;
    }
};
// @lc code=end
