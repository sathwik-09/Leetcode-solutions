class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                int val = s[i]-'0';
                ans+=val;
            }
            else{
                int val= s[i]-'0';
                ans-=val;
            }    
        }
        return ans;
    }
};