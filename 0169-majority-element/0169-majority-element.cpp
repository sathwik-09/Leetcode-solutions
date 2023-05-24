class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums.size()/2;
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        int ans = 0;
        for(auto it:mpp){
            if(it.second>element){
                ans=it.first;
            }
        }
        return ans;
    }
};