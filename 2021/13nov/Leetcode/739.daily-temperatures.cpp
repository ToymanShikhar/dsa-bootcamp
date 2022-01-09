#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if (st.empty()) {
                res[i] = 0;
            } else {
                res[i] = st.top() - i;
            }

            st.push(i);
        }

        return res;
    }
};
// @lc code=end
