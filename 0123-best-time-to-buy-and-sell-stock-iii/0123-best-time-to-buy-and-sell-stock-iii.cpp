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
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int ind = n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int maxi=1; maxi<=2; maxi++){
                    if(buy){
                        curr[buy][maxi]=max(-prices[ind]+after[0][maxi],
                                               after[1][maxi]);
                    }
                    else curr[buy][maxi] = max((prices[ind]+after[1][maxi-1]), after[0][maxi]);
                }
            }
            after = curr;
        }
        return after[1][2];
    }
};