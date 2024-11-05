// class Solution {
// public:
// // Giving me TLE :( // memoization
//       int solve(int i , int j , vector<vector<int>> & dp ,
//       vector<vector<int>> & matrix){
//         if(j<0 || j>= matrix[0].size()) return 1e9;
//         if(i==0) return matrix[0][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int up=matrix[i][j]+solve(i-1, j , dp , matrix);
//         int leftDia=matrix[i][j]+solve(i-1, j-1, dp , matrix);
//         int rightDia=matrix[i][j]+solve(i-1, j+1, dp, matrix);
//         return dp[i][j]= min(up, min(leftDia, rightDia));
//       }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n =matrix.size();
//         vector<vector<int>> dp( n , vector<int>(n, -1));
//         int mini=INT_MAX;
//         for(int j=0;j< n;j++){
//             mini=min(mini,solve(n-1, j,dp, matrix));
//         }
//         return mini;
//     }
// };

// tabulation...
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int u = matrix[i][j] + dp[i - 1][j];
                int ld = matrix[i][j];
                if (j - 1 >= 0)
                    ld += dp[i - 1][j - 1];
                else
                    ld = 1e9;
                int rd = matrix[i][j];
                if (j + 1 < n)
                    rd += dp[i - 1][j + 1];
                else
                    rd = 1e9;
                dp[i][j] = min(u, min(ld, rd));
            }
        }
        int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};