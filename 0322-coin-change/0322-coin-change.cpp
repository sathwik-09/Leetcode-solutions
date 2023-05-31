class Solution {
public:
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
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1,coins,amount,dp);
        if(ans!=1e9) return ans;
        else return -1;
    }
};