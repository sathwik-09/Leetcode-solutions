class Solution {
public:
   
    int solve(int i, int j,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=1e9) return dp[i][j];
        int up = solve(i-1,j,dp);
        int left = solve(i,j-1,dp);
        int ans = up + left;
        return dp[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        return solve(m-1,n-1,dp);
        
    }
};