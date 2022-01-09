#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
   public:
    string gcdOfStrings(string s1, string s2) {
        if (!(s1 + s2 == s2 + s1)) {
            return "";
        }

        return s1.substr(0, __gcd(s1.length(), s2.length()));
    }
};
// @lc code=end

// Brute Force Solution --->
class Solution {
   public:
    bool check(string base, string s1, string s2) {
        int l = base.length();
        int l1 = s1.length();
        int l2 = s2.length();

        int g1 = l1 / l;
        int g2 = l2 / l;

        string first, second;

        for (int i = 0; i < g1; i++) {
            first += base;
        }

        for (int i = 0; i < g2; i++) {
            second += base;
        }

        return (first == s1) and (second == s2);
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1.length() > str2.length()) {
            swap(str1, str2);
        }

        string res;

        for (int l = 1; l <= str1.length(); l++) {
            string curr = str1.substr(0, l);
            if (check(curr, str1, str2)) {
                res = curr;
            }
        }

        return res;
    }
};
