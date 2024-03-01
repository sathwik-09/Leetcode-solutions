class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        /*
        sort(s.rbegin(),s.rend());
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='1') swap(s[i],s[n-1]);
        }
        return s;
        */
        /*
        int oneCnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1') oneCnt++;
        }
        string ans=string(oneCnt-1,'1')+string(n-oneCnt,'0')+'1';
        return ans;
        */
        int left=0,right=n-1;
        while(left<=right){
            if(s[left]=='1') left++;
            if(s[right]=='0') right--;
            if(left<=right && s[left]=='0' && s[right]=='1') swap(s[left],s[right]);
        }
        swap(s[left-1],s[n-1]);
        return s;
        
    }
    
};