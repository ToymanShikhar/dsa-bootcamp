#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=902 lang=cpp
 *
 * [902] Numbers At Most N Given Digit Set
 */

// @lc code=start
class Solution {
   public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string nStr = to_string(n);
        int nLen = nStr.length();
        int digitsLen = digits.size();

        int total = 0;
        for (int i = 1; i < nLen; i++) {
            total += pow(digitsLen, i);
        }

        for (int i = 0; i < nLen; i++) {
            bool isEqual = false;
            for (auto digit : digits) {
                if (digit[0] < nStr[i]) {
                    total += pow(digitsLen, nLen - i - 1);
                }
                if (digit[0] == nStr[i]) {
                    if (i == nLen - 1) {
                        total++;
                    }
                    isEqual = true;
                }
            }
            if (!isEqual) {
                return total;
            }
        }

        return total;
    }
};
// @lc code=end
