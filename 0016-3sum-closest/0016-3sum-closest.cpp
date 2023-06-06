#include <bits/stdc++.h>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 1e9, closestSum = 1e9, i,j,k;
        sort(nums.begin(), nums.end());                             
        for(i=0;i<nums.size()-2;i++){                    
            j = i+1;
            k = nums.size()-1;
            while(j < k){                                
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==target) return target;
                else if(sum<target) j++;
                else k--;
                int close = abs(sum - target);
                if(close<closest){
                    closest = close;
                    closestSum = sum;
                }               
            }
        }
        return closestSum;
    }
};