class Solution {
public:
    /* //MEMOIZATION//
    int solve(int n,vector<int> &dp){
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1,dp) + solve(n-2,dp) + solve(n-3,dp);
    }
    */
    int tribonacci(int n) {
        vector<int>dp(n+1,0);
        for(int i=0;i<=n;i++){
            if(i==0 || i == 1) dp[i] = i;
            else if(i==2) dp[i] = 1;
            else{
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }
        }
        return dp[n];
    }
    
};