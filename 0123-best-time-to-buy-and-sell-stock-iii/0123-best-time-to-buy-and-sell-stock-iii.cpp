class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, int maxi, vector<vector<vector<int>>> &dp, int n){
        if(ind==n || maxi==0) return 0;
        if(dp[ind][buy][maxi]!=-1) return dp[ind][buy][maxi];
        if(buy){
            return dp[ind][buy][maxi]=max((-prices[ind]+solve(ind+1,0,prices,maxi,dp,n)),solve(ind+1,1,prices,maxi,dp,n));
        }
        return dp[ind][buy][maxi] = max((prices[ind]+solve(ind+1,1,prices,maxi-1,dp,n)), solve(ind+1,0,prices,maxi,dp,n));
        return dp[ind][buy][maxi];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,prices,2,dp,n);
    }
};