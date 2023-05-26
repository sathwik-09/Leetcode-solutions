class Solution {
public:
    /*
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> dp){
        int mod = 2e9+1;
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = solve(i-1,j,obstacleGrid,dp);
        int left = solve(i,j-1,obstacleGrid,dp);
        int ans = up + left;
        return dp[i][j] = ans%mod;
        
    }
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                } 
                else if(i==0 && j==0){
                    dp[i][j]=1;   
                }
                else{
                    int top=0,right=0;
                    if(i>0) top = dp[i-1][j];
                    if(j>0) right = dp[i][j-1];
                    dp[i][j] = top + right;
                }
            }
        }
        return dp[m-1][n-1];
    }
};