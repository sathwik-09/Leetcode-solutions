class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        vector<int> arr3;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        int x=0,y=0;
        while(x<nums.size()/2){
            arr3.push_back(arr1[x]);
            x++;
            arr3.push_back(arr2[y]);
            y++;
        }
        return arr3;
    }
};