class Solution {
public:
    /*
    int solve(int index, vector<int>& coins, int amount,vector<vector<int>> dp){
        if(index==0){
            return (amount%coins[index]==0) ;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int exclude = solve(index-1, coins, amount,dp);
        int include = 0;
        if(coins[index]<=amount) include = solve(index,coins,amount-coins[index],dp);
        return dp[index][amount]=include+exclude;
    }
    */
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0; i<=amount; i++){
            dp[0][i] = (i%coins[0]==0) ;
        }
        for(int index=1; index<n; index++){
            for(int target=0; target<=amount; target++){
                long long exclude = dp[index-1][target];
                long long include = 0;
                if(coins[index]<=target) include = dp[index][target-coins[index]];
                dp[index][target]=include+exclude;
            }
        }
        return dp[n-1][amount];
    }
};