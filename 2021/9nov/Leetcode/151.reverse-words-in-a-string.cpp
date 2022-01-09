#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        int n = s.length();

        int i = 0;
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (s[j] != ' ') {
                s[i] = s[j];
                i++;
                flag = 1;
            } else if (s[j] == ' ' and flag == 1) {
                s[i] = s[j];
                i++;
                flag = 0;
            }
        }
        s.erase(i);

        n = s.length();

        int start = 0;
        int end = 0;
        while (end < n and s[end] != ' ') {
            end++;
        }

        while (start < n and end < n) {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            end = start;
            while (end < n and s[end] != ' ') {
                end++;
            }
        }

        if (start < n) {
            reverse(s.begin() + start, s.begin() + end);
        }

        return s;
    }
};
// @lc code=end
