class Solution {
public:
    int solve(int index, vector<int>& cost,vector<int> &dp){
        if(index<0) return 0;
        if(index==0 || index==1){
            return cost[index];
        }
        if(dp[index]!=-1) return dp[index];
        return dp[index]=cost[index] + min(solve(index-1,cost,dp),solve(index-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
};