class Solution {
public:
    /*
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
    */
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mpp;
        int maxi=0;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto i:mpp){
            maxi=max(maxi,i.second);
        }
        for(int i=0; i<maxi; i++){
            vector<int> temp;
            for(auto& i:mpp){
                if(i.second>0){
                    temp.push_back(i.first);
                    i.second--;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};