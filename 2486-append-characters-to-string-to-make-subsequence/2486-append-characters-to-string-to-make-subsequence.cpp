class Solution {
public:
    int appendCharacters(string s, string t) {
        int j= 0;
        int n = t.size(), count = 0;
        for(int i=0; i<s.size(); i++){
            while(i<s.size() && j<t.size() && s[i] == t[j]){
                count++; 
                j++;
                i++;
            }       
        }
        return n-count;
    }
};