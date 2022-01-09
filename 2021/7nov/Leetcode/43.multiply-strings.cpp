#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0") {
            return "0";
        }
        int n1 = num1.length();
        int n2 = num2.length();

        vector<int> res(n1 + n2, 0);

        int pf = 0;
        int k = res.size() - 1;

        int product;
        int carry;

        for (int i = n1 - 1; i >= 0; i--) {
            carry = 0;
            k = res.size() - 1;
            for (int l = 0; l < pf; l++) {
                k--;
            }
            for (int j = n2 - 1; j >= 0; j--) {
                product = (num1[i] - '0') * (num2[j] - '0') + carry + res[k];
                res[k] = product % 10;
                carry = product / 10;
                k--;
            }
            while (carry) {
                product = carry + res[k];
                res[k] = product % 10;
                carry = product / 10;
                k--;
            }
            pf++;
        }

        string ans;
        k = 0;
        while (res[k] == 0) {
            k++;
        }
        while (k < res.size()) {
            ans += to_string(res[k]);
            k++;
        }

        return ans;
    }
};
// @lc code=end