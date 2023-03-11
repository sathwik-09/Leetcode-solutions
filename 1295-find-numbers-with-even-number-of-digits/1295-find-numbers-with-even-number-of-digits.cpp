class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int even=0;
        for(int i=0; i<nums.size(); i++){
            int k = nums[i];
            int count=0;
            while(k>0){ 
                k=k/10;
                count++;
            }
            if(count%2==0){
                even++;
            }
            
        }
        return even;
    }
};