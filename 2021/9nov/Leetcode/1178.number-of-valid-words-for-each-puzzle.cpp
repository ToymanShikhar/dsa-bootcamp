#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1178 lang=cpp
 *
 * [1178] Number of Valid Words for Each Puzzle
 */

// @lc code=start
class Solution {
   public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<char, vector<int>> mp;

        for (string word : words) {
            int mask = 0;
            for (char ch : word) {
                int bit = ch - 'a';
                mask = mask | (1 << bit);
            }

            unordered_set<char> st;
            for (char ch : word) {
                if (st.find(ch) == st.end()) {
                    mp[ch].push_back(mask);
                    st.insert(ch);
                }
            }
        }

        vector<int> res;

        for (string pz : puzzles) {
            int pmask = 0;
            for (char ch : pz) {
                int bit = ch - 'a';
                pmask = pmask | (1 << bit);
            }

            vector<int> toSearch = mp[pz[0]];
            int cnt = 0;
            for (int num : toSearch) {
                if ((num & pmask) == num) {
                    cnt++;
                }
            }

            res.push_back(cnt);
        }

        return res;
    }
};
// @lc code=end
