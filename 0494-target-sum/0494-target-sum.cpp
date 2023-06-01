class Solution {
public:
    int solve(vector<int> &nums,int target,int ans,int index){
        if(index==nums.size()&&ans==target)
          return 1;
        if(index>=nums.size())
          return 0;

        return solve(nums,target,ans+nums[index],index+1)+solve(nums,target,ans-nums[index],index+1);
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0,i=0;
        return solve(nums,target,ans,i);
    }
};