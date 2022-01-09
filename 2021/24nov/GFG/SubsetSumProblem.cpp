#include <bits/stdc++.h>
using namespace std;

// Bottom Up DP Approach
class Solution {
   public:
    bool isSubsetSum(int N, int arr[], int sum) {
        int dp[N + 1][sum + 1];
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= sum; i++) {
            dp[0][i] = false;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                bool consider = false;
                if (arr[i - 1] <= sum) {
                    consider = dp[i - 1][j - arr[i - 1]];
                }
                bool notConsider = dp[i - 1][j];

                dp[i][j] = consider or notConsider;
            }
        }

        return dp[N][sum];
    }
};

// Top Down DP Approach which gives TLE on GFG
class Solution {
   public:
    bool isPossible(int arr[], int N, int curr, int sum, unordered_map<int, unordered_map<int, bool>>& dp) {
        if (sum == 0) {
            return true;
        }
        if (curr >= N) {
            return false;
        }

        if (dp.count(curr) and dp[curr].count(sum)) {
            return dp[curr][sum];
        }

        bool consider = false;
        if (arr[curr] <= sum) {
            consider = isPossible(arr, N, curr + 1, sum - arr[curr], dp);
        }

        bool notConsider = isPossible(arr, N, curr + 1, sum, dp);

        return dp[curr][sum] = consider or notConsider;
    }

    bool isSubsetSum(int N, int arr[], int sum) {
        unordered_map<int, unordered_map<int, bool>> dp;
        return isPossible(arr, N, 0, sum, dp);
    }
};