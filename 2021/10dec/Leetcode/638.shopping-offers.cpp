#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 */

// @lc code=start
class Solution {
   public:
    unordered_map<string, int> dp;
    bool checkPossible(vector<int>& v) {
        for (auto x : v) {
            if (x < 0) {
                return false;
            }
        }
        return true;
    }

    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        string currKey;
        for (int i = 0; i < needs.size(); i++) {
            currKey += to_string(needs[i]) + "_";
        }

        if (dp.count(currKey)) {
            return dp[currKey];
        }

        //No offer
        int cost = INT_MAX;
        int tempAns = 0;
        for (int i = 0; i < price.size(); i++) {
            tempAns += price[i] * needs[i];
        }
        cost = min(cost, tempAns);

        //Take any offer
        for (auto offer : special) {
            vector<int> v(needs);
            for (int i = 0; i < v.size(); i++) {
                v[i] = v[i] - offer[i];
            }

            if (checkPossible(v)) {
                cost = min(cost, offer[offer.size() - 1] + solve(price, special, v));
            }
        }

        return dp[currKey] = cost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        dp.clear();
        return solve(price, special, needs);
    }
};
// @lc code=end
