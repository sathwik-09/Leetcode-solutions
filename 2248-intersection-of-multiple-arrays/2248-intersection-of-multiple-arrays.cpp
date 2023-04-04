class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size(); 
        map<int,int> mpp;
        vector<int> v;
        for(int row=0;row<n;row++){
            for(int col=0;col<nums[row].size();col++){
                mpp[nums[row][col]]++;
            }
        }
        for(auto i : mpp){
            if(i.second == n){
                v.emplace_back(i.first);
            }
        }
        return v;
    }
};