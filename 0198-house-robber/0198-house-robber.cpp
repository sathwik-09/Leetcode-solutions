
//    MEMOIZATION
class Solution {
public:
    int solve(int index, vector<int> nums, vector<int>& dp){
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int maxi = INT_MIN;
        int left = nums[index] + solve(index-2,nums,dp);
        int right = solve(index-1,nums,dp);
        maxi = max(left,right);
        return dp[index]=maxi;
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
    }
};