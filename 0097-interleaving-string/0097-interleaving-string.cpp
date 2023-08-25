class Solution {
public:
    bool helper(int i,int j,int k,string &s1, string &s2, string &s3){
        if(i<0 && j<0 && k<0)
            return true;
        if(i>=0 && j>=0 && k>=0 && s1[i]==s3[k] && s2[j]==s3[k])
            return helper(i-1,j,k-1,s1,s2,s3) || helper(i,j-1,k-1,s1,s2,s3) ;
        else if (i>=0 && k>=0 && s1[i]==s3[k])
            return helper(i-1,j,k-1,s1,s2,s3);
        else if(j>=0 && k>=0 && s2[j] == s3[k] )
            return helper(i,j-1,k-1,s1,s2,s3);
        else
            return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;

        return helper(s1.length()-1,s2.length()-1,s3.length()-1,s1,s2,s3);
    }
};