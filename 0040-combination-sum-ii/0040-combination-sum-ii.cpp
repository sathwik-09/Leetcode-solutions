class Solution {
private:
    void getSum(int index, int target, vector<int>& arr, vector<vector<int>>& ans,vector<int>& output){
        if(target==0){
            ans.push_back(output);
            return;
        }
        for(int i=index; i<arr.size(); i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            output.push_back(arr[i]);
            getSum(i+1,target-arr[i],arr,ans,output);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(candidates.begin(),candidates.end());
        getSum(0,target,candidates,ans,output);
        return ans;
    }
};