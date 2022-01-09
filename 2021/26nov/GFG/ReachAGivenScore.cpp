// Consider a game where a player can score 3 or 5 or 10 points in a move.
// Given a total score n, find number of distinct combinations to reach the given score.
// Complete the function count().

int ways(vector<int>& coins, int curr, int amount, int dp[][5]) {
    if (amount == 0) {
        return 1;
    }
    if (curr >= coins.size()) {
        return 0;
    }

    if (dp[amount][curr] != -1) {
        return dp[amount][curr];
    }

    int consider = 0;
    if (coins[curr] <= amount) {
        consider = ways(coins, curr, amount - coins[curr], dp);
    }

    int notConsider = ways(coins, curr + 1, amount, dp);

    return dp[amount][curr] = consider + notConsider;
}

int change(int amount, vector<int>& coins) {
    int dp[amount + 1][5];
    memset(dp, -1, sizeof(dp));

    return ways(coins, 0, amount, dp);
}

long long int count(long long int n) {
    long long int table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;  // If 0 sum is required number of ways is 1.

    // Your code here
    vector<int> nums{3, 5, 10};
    table[n] = change(n, nums);

    return table[n];
}