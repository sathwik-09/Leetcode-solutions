class Solution {
public:
    /*
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> dp){
        int n = matrix.size();
        if(j<0 || j>n-1) return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int st = matrix[i][j] + solve(i-1,j,matrix,dp);
        int leftDig = matrix[i][j] + solve(i-1,j-1,matrix,dp);
        int rightDig = matrix[i][j] + solve(i-1,j+1,matrix,dp);
        return dp[i][j] = min(st,min(leftDig,rightDig));
    }
    */
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int st = matrix[i][j] + dp[i-1][j];
                int leftDig = matrix[i][j];
                if(j-1>=0) leftDig +=  dp[i-1][j-1];
                else leftDig+=1e9;
                int rightDig = matrix[i][j];
                if(j+1<n) rightDig += dp[i-1][j+1];
                else rightDig += 1e9;
                dp[i][j] = min(st,min(leftDig,rightDig));
            }
        }
        int mini = INT_MAX;
        for(int j=0; j<n; j++){
            mini = min(mini,dp[n-1][j]);
        }
        return mini;
    }
};