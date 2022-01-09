#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
// Solution: Time-->O(n) and Space-->O(1)
class Solution {
   public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                int len = 2 * right;
                ans = max(ans, len);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }

        left = right = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                int len = 2 * right;
                ans = max(ans, len);
            } else if (right < left) {
                left = 0;
                right = 0;
            }
        }

        return ans;
    }
};
// @lc code=end

// Solution: Time-->O(n) and Space-->O(n)
class Solution {
   public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    int len = i - st.top();
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};
