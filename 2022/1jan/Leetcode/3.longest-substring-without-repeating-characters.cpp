#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char, int> m;

        while (j < s.length()) {
            m[s[j]]++;

            if (m.size() == (j - i + 1)) {
                ans = max(ans, j - i + 1);
            } else {
                while (m.size() < (j - i + 1)) {
                    m[s[i]]--;
                    if (m[s[i]] == 0) {
                        m.erase(s[i]);
                    }
                    i++;
                }

                ans = max(ans, j - i + 1);
            }

            j++;
        }

        return ans;
    }
};
// @lc code=end
