class Solution {
public:
    /*
    int solve(int ind, int buy, vector<int>& prices, int maxi, vector<vector<vector<int>>> &dp, int n){
        if(ind==n || maxi==0) return 0;
        if(dp[ind][buy][maxi]!=-1) return dp[ind][buy][maxi];
        if(buy){
            return dp[ind][buy][maxi]=max((-prices[ind]+solve(ind+1,0,prices,maxi,dp,n)),solve(ind+1,1,prices,maxi,dp,n));
        }
        return dp[ind][buy][maxi] = max((prices[ind]+solve(ind+1,1,prices,maxi-1,dp,n)), solve(ind+1,0,prices,maxi,dp,n));
        return dp[ind][buy][maxi];
    }
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind = n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int maxi=1; maxi<=2; maxi++){
                    if(buy){
                        dp[ind][buy][maxi]=max(-prices[ind]+dp[ind+1][0][maxi],
                                               dp[ind+1][1][maxi]);
                    }
                    else dp[ind][buy][maxi] = max((prices[ind]+dp[ind+1][1][maxi-1]), dp[ind+1][0][maxi]);
                }
            }
        }
        return dp[0][1][2];
    }
};