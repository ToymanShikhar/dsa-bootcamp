// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

class Solution {
   public:
    void solve(int n, int num, int size, vector<int>& ans) {
        if (size == n) {
            ans.push_back(num);
        }

        int start = num % 10;
        for (int i = start + 1; i < 10; i++) {
            solve(n, num * 10 + i, size + 1, ans);
        }
    }

    vector<int> increasingNumbers(int N) {
        vector<int> ans;
        if (N == 1) {
            ans.push_back(0);
        }

        solve(N, 0, 0, ans);
        return ans;
    }
};