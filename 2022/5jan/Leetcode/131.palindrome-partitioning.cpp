#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void dfs(int idx, string& s, vector<string>& path, vector<vector<string>>& res) {
        //Base Condn
        if (idx == s.length()) {
            res.push_back(path);
            return;
        }

        // Recursive Case
        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                path.push_back(s.substr(idx, i - idx + 1));
                dfs(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(0, s, path, res);
        return res;
    }
};
// @lc code=end
