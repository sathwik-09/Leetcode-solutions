class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        int ans=-1;
        for(int i=0; i <nums.size(); i++){
            hash[nums[i]]++;
        }
        for(auto i:hash){
            if(i.second>nums.size()/2) ans=i.first;
        }
        return ans;
    }
};