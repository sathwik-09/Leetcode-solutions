class Solution {
public:
    /*
    bool solve(int i, int j, string &s, string &p){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j]=='*') j--;
                else return false;
            }
            return true;
        }
        if(s[i]==p[j] || p[j]=='?') return solve(i-1,j-1,s,p);
        if(p[j]=='*') return solve(i-1,j,s,p) || solve(i,j-1,s,p);
        return false;
    }
    */
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<bool> prev(m+1);
        prev[0]=true;
        bool flag=true;
        for(int i=1;i<=m;i++){
            if(p[i-1]!='*')
                flag=false;
            prev[i]=flag;
        }
        vector<bool> curr(m+1);
        for(int i=1;i<=n;i++){
            curr[0]=false;
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    curr[j]=prev[j-1];
                else if(p[j-1]=='*')
                    curr[j] = prev[j] || curr[j-1];
                else curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }
};