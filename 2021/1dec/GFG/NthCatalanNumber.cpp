// Find Nth Catalan Number

class Solution {
   public:
    //Function to find the nth catalan number.
    cpp_int catalan(int n, unordered_map<int, cpp_int>& dp) {
        if (n <= 1) {
            return 1;
        }

        if (dp.count(n)) {
            return dp[n];
        }

        cpp_int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (catalan(i, dp) * catalan(n - i - 1, dp));
        }

        return dp[n] = ans;
    }
    cpp_int findCatalan(int n) {
        unordered_map<int, cpp_int> dp;
        return catalan(n, dp);
    }
};