class Solution {
public:
   /* 
    int solve(int i, int j,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=1e9) return dp[i][j];
        int up = solve(i-1,j,dp);
        int left = solve(i,j-1,dp);
        int ans = up + left;
        return dp[i][j]=ans;
    }
    */
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
};