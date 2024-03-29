class Solution {
public:
    /*
    int solve(int index, vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(index==0){
            if(amount%coins[index]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int exclude = 0 + solve(index-1, coins, amount,dp);
        int include = INT_MAX;
        if(coins[index]<=amount) include = 1 + solve(index,coins,amount-coins[index],dp);
        return dp[index][amount]=min(include,exclude);
    }
    */
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int t=0; t<=amount; t++){
            if(t%coins[0]==0){
                prev[t]=t/coins[0];
            }
            else prev[t]=1e9;
        }
        for(int index=1; index<n; index++){
            for(int t=0; t<=amount; t++){
                int exclude = 0 + prev[t];
                int include = INT_MAX;
                if(coins[index]<=t){
                    include = 1 + curr[t-coins[index]];
                } 
                curr[t]=min(include,exclude);
            }
            prev=curr;
            
        }
        int ans = prev[amount];
        if(ans!=1e9) return ans;
        else return -1;
    }
};