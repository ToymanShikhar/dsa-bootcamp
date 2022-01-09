#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start

// USE STACK INSTEAD OF SET TO GET BETTER TIME COMPLEXITY

class Solution {
   public:
    string minRemoveToMakeValid(string s) {
        set<int> st;

        string res;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                res += s[i];
                st.insert(res.length() - 1);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    continue;
                }
                res += s[i];
                st.erase(--st.end());
            } else {
                res += s[i];
            }
        }

        string ans;
        int i = 0;
        auto ele = st.begin();
        for (; i < res.length(); i++) {
            if (ele == st.end()) {
                break;
            }
            if (i == *ele) {
                ele++;
                continue;
            }

            ans += res[i];
        }
        while (i < res.length()) {
            ans += res[i];
            i++;
        }
        return ans;
    }
};
// @lc code=end
