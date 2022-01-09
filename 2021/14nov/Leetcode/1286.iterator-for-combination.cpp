#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */

// @lc code=start
class CombinationIterator {
   public:
    string s;
    int l;
    int n;
    vector<string> res;

    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        l = combinationLength;
        n = characters.length();
        res.clear();

        for (int i = 0; i < pow(2, n); i++) {
            int cnt = 0;
            int num = i;

            while (num > 0) {
                cnt += num & 1;
                num = num >> 1;
            }

            num = i;
            if (cnt == l) {
                string word;

                for (int j = 0; j < n; j++) {
                    if ((num >> j) & 1) {
                        word += s[j];
                    }
                }

                res.push_back(word);
            }
        }

        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
    }

    string next() {
        string nxt = res[res.size() - 1];
        res.pop_back();
        return nxt;
    }

    bool hasNext() {
        return (res.size() != 0);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
