class Solution {
public:
    bool isPalindrome(string str){
        int right=str.size()-1;
        for(int i=0; i<str.size()/2; i++){
            if(str[i]!=str[right]){return false; break;}
            else right--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(int i=0; i<words.size(); i++){
            if(isPalindrome(words[i])){
                ans=words[i];
                break;
            }
        }
        return ans;
    }
};