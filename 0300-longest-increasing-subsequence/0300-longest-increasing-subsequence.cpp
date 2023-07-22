class Solution {
public:
    int solve(int ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int notTake = solve(ind+1,prev_ind,n,nums,dp), take = 0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            take = 1+solve(ind+1,ind,n,nums,dp);
        }
        return dp[ind][prev_ind+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,n,nums,dp);
    }
};