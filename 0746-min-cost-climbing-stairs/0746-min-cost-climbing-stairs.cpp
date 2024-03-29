class Solution {
public:
    /*
    int solve(int index, vector<int>& cost,vector<int> &dp){
        if(index<0) return 0;
        if(index==0 || index==1){
            return cost[index];
        }
        if(dp[index]!=-1) return dp[index];
        return dp[index]=cost[index] + min(solve(index-1,cost,dp),solve(index-2,cost,dp));
    }
    */
    int minCostClimbingStairs(vector<int>& cost) {
        /*
        int n = cost.size();
        vector<int> dp(n,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
            
        }
        return min(dp[n-1],dp[n-2]);
        */
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];
        for(int i=2; i<n; i++){
            int curr = cost[i] + min(first,second);
            first = second;
            second = curr;
        }
        return min(first,second);
    }
};