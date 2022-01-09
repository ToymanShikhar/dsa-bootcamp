#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
   public:
    // Without using extra stack space
    // Use top variable instead of stack
    unordered_map<char, char> m;
    int nextTop(string& s, int top) {
        int right = 0;
        while (top >= 0) {
            if (m.count(s[top])) {
                right++;
            } else {
                right--;
            }
            if (right == -1) {
                return top;
            }
            top--;
        }

        return top;
    }

    bool isValid(string s) {
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';

        int top = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[') {
                top = i;
            } else {
                if (top == -1 or s[top] != m[s[i]]) {
                    return false;
                } else {
                    top = nextTop(s, top - 1);
                }
            }
        }

        if (top == -1) {
            return true;
        }
        return false;
    }
};
// @lc code=end
