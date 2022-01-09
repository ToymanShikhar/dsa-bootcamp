#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1737 lang=cpp
 *
 * [1737] Change Minimum Characters to Satisfy One of Three Conditions
 */

// @lc code=start
class Solution {
   public:
    int minCharacters(string A, string B) {
        int nA = A.length();
        int nB = B.length();
        vector<int> arrA(26, 0);
        vector<int> arrB(26, 0);

        for (auto ch : A) {
            arrA[ch - 'a']++;
        }
        for (auto ch : B) {
            arrB[ch - 'a']++;
        }

        int preA = arrA[0];
        int preB = arrB[0];

        // Case 3
        int maxA = 0, maxB = 0;
        for (int i = 0; i < 26; i++) {
            maxA = max(maxA, arrA[i]);
            maxB = max(maxB, arrB[i]);
        }
        int res = nA + nB - maxA - maxB;

        // Case 1 and 2
        for (int i = 1; i < 26; i++) {
            res = min(res, nA - preA + preB);
            res = min(res, nB - preB + preA);
            preA += arrA[i];
            preB += arrB[i];
        }

        return res;
    }
};
// @lc code=end
