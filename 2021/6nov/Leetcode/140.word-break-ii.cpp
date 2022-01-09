#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
   public:
    bool matches(string s, int i, string s1) {
        int j = 0;

        while (i < s.length() and j < s1.length()) {
            if (s[i] != s1[j]) {
                return false;
            }
            i++;
            j++;
        }
        if (j == s1.length()) {
            return true;
        }

        return false;
    }

    void check(string& s, int i, vector<string>& dict, vector<string>& res, string& temp) {
        if (i == s.length()) {
            temp.pop_back();
            res.push_back(temp);
            temp += ' ';
            return;
        }

        for (int j = 0; j < dict.size(); j++) {
            if (matches(s, i, dict[j])) {
                temp += dict[j];
                temp += ' ';
                check(s, i + dict[j].length(), dict, res, temp);
                int num = dict[j].length() + 1;
                while (num > 0) {
                    temp.pop_back();
                    num--;
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string d;

        check(s, 0, wordDict, res, d);

        return res;
    }
};
// @lc code=end
