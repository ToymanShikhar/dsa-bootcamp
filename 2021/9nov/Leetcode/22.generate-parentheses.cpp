#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
   public:
    vector<string> res;

    void generate(int left, int right, int n, string& s) {
        if (left == n and right == n) {
            res.push_back(s);
            return;
        }

        if (left < n) {
            s.push_back('(');
            generate(left + 1, right, n, s);
            s.pop_back();
        }

        if (left > right) {
            s.push_back(')');
            generate(left, right + 1, n, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        generate(0, 0, n, s);
        return res;
    }
};
// @lc code=end
