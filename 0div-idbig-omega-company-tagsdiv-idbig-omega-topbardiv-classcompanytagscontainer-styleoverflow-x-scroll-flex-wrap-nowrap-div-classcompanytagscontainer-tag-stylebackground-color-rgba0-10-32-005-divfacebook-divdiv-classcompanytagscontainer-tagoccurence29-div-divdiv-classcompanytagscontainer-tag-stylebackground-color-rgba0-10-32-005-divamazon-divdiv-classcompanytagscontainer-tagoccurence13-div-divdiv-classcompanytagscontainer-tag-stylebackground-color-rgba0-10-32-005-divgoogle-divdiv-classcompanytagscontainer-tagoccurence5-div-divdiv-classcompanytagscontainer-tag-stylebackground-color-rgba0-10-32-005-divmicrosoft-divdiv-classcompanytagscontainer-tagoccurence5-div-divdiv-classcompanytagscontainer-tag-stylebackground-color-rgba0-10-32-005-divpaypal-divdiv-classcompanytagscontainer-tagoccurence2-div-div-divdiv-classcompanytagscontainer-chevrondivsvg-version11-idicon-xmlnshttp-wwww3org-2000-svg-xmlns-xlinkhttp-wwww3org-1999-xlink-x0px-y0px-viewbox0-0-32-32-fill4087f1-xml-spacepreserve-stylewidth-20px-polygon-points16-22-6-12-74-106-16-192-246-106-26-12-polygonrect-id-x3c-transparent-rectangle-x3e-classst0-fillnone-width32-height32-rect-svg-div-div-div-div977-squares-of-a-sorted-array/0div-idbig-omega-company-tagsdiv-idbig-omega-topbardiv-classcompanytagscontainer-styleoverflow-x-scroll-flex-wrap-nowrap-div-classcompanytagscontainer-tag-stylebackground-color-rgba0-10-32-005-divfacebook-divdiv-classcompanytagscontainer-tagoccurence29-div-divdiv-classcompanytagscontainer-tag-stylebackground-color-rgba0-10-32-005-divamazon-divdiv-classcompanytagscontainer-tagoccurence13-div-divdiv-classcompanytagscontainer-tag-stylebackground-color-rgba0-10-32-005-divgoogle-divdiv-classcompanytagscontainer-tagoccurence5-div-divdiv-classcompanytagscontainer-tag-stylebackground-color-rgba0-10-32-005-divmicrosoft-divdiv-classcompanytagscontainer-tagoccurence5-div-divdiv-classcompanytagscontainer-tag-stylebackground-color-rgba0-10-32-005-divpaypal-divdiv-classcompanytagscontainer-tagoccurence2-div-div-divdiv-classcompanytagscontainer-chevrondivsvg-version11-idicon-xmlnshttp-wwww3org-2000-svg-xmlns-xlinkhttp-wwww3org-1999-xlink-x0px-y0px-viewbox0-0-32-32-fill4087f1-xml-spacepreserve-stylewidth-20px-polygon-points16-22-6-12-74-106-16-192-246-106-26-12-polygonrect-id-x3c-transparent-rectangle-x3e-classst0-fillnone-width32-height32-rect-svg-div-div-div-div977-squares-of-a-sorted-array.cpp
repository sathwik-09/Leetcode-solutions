class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            int ans=1;
            ans=abs(nums[i]*nums[i]);
            v.push_back(ans);
        }
        sort(v.begin(),v.end());
        
        return v;
    }
};