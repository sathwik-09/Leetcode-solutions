class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int countMajority = nums.size()/3;
        unordered_map<int, int> mpp;
        vector<int> output;
        for(auto num : nums){
            mpp[num]++;
        }
        for(auto num : mpp){
            if(num.second > countMajority){
                output.push_back(num.first);
            }
        }
        return output;
    }
};