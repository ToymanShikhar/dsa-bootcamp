#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */

// @lc code=start
class Solution {
   public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        stringstream ss1(s1);
        stringstream ss2(s2);
        deque<string> d1;
        deque<string> d2;

        while (ss1 >> s1) {
            d1.push_back(s1);
        }
        while (ss2 >> s2) {
            d2.push_back(s2);
        }

        int n1 = d1.size();
        int n2 = d2.size();

        while (n1 < n2 ? !d1.empty() : !d2.empty()) {
            if (d1.front() == d2.front()) {
                d1.pop_front();
                d2.pop_front();
            } else if (d1.back() == d2.back()) {
                d1.pop_back();
                d2.pop_back();
            } else {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
