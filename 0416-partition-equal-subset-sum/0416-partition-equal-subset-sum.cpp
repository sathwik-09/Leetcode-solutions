class Solution {
public:
    bool isSubsetSum(vector<int> &nums, int k , int n){
        // code here 
        vector<bool> prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        if(nums[0]<=k) prev[nums[0]] = true;
        for(int index = 1; index<n; index++){
            for(int target=1; target<=k; target++){
                bool exclude = prev[target];
                bool include = false;
                if(target>=nums[index]){
                    include = prev[target-nums[index]];
                }
                curr[target] = exclude | include;
            }
            prev = curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int totalSum = 0;
        for(int i=0; i<N; i++){
            totalSum += nums[i];
        }
        if(totalSum % 2) return false;
        int target = totalSum/2;
        return isSubsetSum(nums,target,N);
    }
};