class Solution {
public:
    bool isPerfectSquare(int num) {
        double a=pow(num,0.5);
        for(int i=1;i<a+1;i++){
            if(i==a)
            return true;
        }
        return false;
    }
};