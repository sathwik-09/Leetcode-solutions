class Solution {
public:
    /*
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
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int ind=n-1; ind>=0; ind--){
            for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
                int notTake = dp[ind+1][prev_ind+1], take = 0;
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                    take = 1+dp[ind+1][ind+1];
                }
                dp[ind][prev_ind+1]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
    */
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=1; i<n; i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return len;
    }
};