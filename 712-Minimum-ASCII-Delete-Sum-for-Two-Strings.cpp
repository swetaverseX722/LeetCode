class Solution {
public:
    int n;
    int m;

    int solve(int i, int j, vector<vector<int>>& dp, string& s1, string& s2) {
        if (i >= n && j >= m) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (i >= n && j < m) {
            // All characters of s1 are deleted, so return the sum of remaining characters of s2
            dp[i][j] = s2[j] + solve(i, j + 1, dp, s1, s2);
        } 
        else if (j >= m && i < n) {
            // All characters of s2 are deleted, so return the sum of remaining characters of s1
            dp[i][j] = s1[i] + solve(i + 1, j, dp, s1, s2);
        } 
        else if (s1[i] == s2[j]) {
            dp[i][j] = solve(i + 1, j + 1, dp, s1, s2);  // No cost if characters match
        } 
        else {
            int delete_s1_i = s1[i] + solve(i + 1, j, dp, s1, s2);  // Delete s1[i]
            int delete_s2_j = s2[j] + solve(i, j + 1, dp, s1, s2);  // Delete s2[j]
            dp[i][j] = min(delete_s1_i, delete_s2_j);  // Take the minimum cost
        }

        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.length();
        m = s2.length();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(0, 0, dp, s1, s2);
    }
};
