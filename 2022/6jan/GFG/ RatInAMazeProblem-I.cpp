// Expected Time Complexity: O((3N^2)).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

class Solution {
   public:
    void solve(vector<vector<int>> &m, int n, int r, int c, string s, vector<string> &ans) {
        if (r < 0 or r >= n or c < 0 or c >= n or m[r][c] == 0) {
            return;
        }
        if (r == n - 1 and c == n - 1) {
            ans.push_back(s);
        }

        m[r][c] = 0;
        solve(m, n, r + 1, c, s + "D", ans);
        solve(m, n, r, c - 1, s + "L", ans);
        solve(m, n, r, c + 1, s + "R", ans);
        solve(m, n, r - 1, c, s + "U", ans);
        m[r][c] = 1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        solve(m, n, 0, 0, "", ans);
        return ans;
    }
};