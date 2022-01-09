#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
class Solution {
   public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int n = time.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int num = time[i] % 60;
            int rem = 60 - num;
            if (rem == 60) {
                rem = 0;
            }
            if (m.count(rem)) {
                res += m[rem];
            }

            m[num]++;
        }

        return res;
    }
};
// @lc code=end
