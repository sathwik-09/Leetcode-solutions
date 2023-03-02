class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> lsum,output;
        int leftsum=0;
        //calculating left sum
        for(int i=0; i<nums.size();i++){
            lsum.emplace_back(leftsum);
            leftsum+=nums[i];
        }
        //calculating right sum
        int rightsum=0;
        vector<int> rsum(nums.size(),0);
        for(int i=nums.size()-1; i>=0; i--){
            rsum[i]=rightsum;
            rightsum+=nums[i];
        }
        
        for(int i=0; i<nums.size(); i++){
            output.emplace_back(abs(lsum[i]-rsum[i]));
        }
        return output;
    }
};