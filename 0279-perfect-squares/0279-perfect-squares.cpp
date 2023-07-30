class Solution {
public:
    /*
    int solve(int i, int n,vector<int> &dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        if(i*i<=n){
            return dp[n]=min(1+solve(i,n-i*i,dp),solve(i+1,n,dp));
        }
        return dp[n]=1e5;
    }
    */
    int numSquares(int n) {
        vector<int>dp(n+1, 1e5);
        dp[0]=0;
        int j=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(1+dp[i-j*j], dp[i]);
            }
        }
        return dp[n];
    }
};