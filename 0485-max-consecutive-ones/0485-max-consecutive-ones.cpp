class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int curr = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                curr++;
                maxi = max(maxi,curr);
            }
            else curr=0;
        }
        return maxi;
    }
};