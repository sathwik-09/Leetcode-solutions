class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans="";
        for(auto it:words){
            ans+=it[0];
        }
        return s==ans;
    }
};