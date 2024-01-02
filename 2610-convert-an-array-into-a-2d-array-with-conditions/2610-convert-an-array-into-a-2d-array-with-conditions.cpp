class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mpp;
        for(auto el:nums){
            mpp[el]++;
            if(ans.size()<mpp[el]){
                ans.push_back({});
            }
            ans[mpp[el]-1].push_back(el);
        }
        return ans;
    }
};