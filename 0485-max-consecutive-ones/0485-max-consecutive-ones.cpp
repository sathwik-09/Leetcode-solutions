class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxCount=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                count++;
                maxCount=max(count,maxCount);
            }
            else count = 0;
        }
        return max(count,maxCount);
    }
};