class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
        if(i>j) return 0;
        int maxi = INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i; ind<=j; ind++){
            int cost = nums[i-1]*nums[ind]*nums[j+1]+solve(i,ind-1,nums,dp)+solve(ind+1,j,nums,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,nums,dp);
    }
};