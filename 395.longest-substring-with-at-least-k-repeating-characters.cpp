#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution {
   public:
    int longestSubstring(string s, int k) {
        int i = 0;
        int j = 0;
        unordered_map<char, int> m;
        int count = 0;
        int ans = 0;

        while (j < s.length()) {
            m[s[j]]++;
            if (m[s[j]] == k) {
                count++;
            }

            if (m.size() == count) {
                ans = max(ans, j - i + 1);
            } else if (m.size() > count) {
                while (m.size() > count) {
                    m[s[i]]--;
                    if (m[s[i]] < k) {
                        count--;
                    }
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
