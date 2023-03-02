class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int, int> mp;
        for(auto i : nums1){
            mp[i[0]] += i[1];
        }
        
        for(auto i : nums2){
            mp[i[0]] += i[1];
        }
        
        for(auto s : mp){
            ans.push_back({s.first, s.second});
        }
        
        return ans;
    }
};