class Solution {
public:
    int bulbSwitch(int n) {
        int low=0;
        int high=n;
        while(low<=high){
            long mid=low+(high-low)/2;
            if((mid*mid)==n)
                return mid;
            else if((mid*mid)<n)
                low=mid+1;
            else
                high=mid-1;
        }
        return low-1;
    }
};