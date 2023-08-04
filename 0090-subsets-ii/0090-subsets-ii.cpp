class Solution {
private:
    void solve(int index,vector<int> &nums, vector<int> &output,vector<vector<int>> &ans){
        ans.push_back(output);
        for(int i=index; i<nums.size(); i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            output.push_back(nums[i]);
            solve(i+1,nums,output,ans);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> output;
        sort(nums.begin(),nums.end());
        solve(0,nums,output,ans);
        return ans;
    }
};