class Solution {
public:
    string reverseWords(string s) {
        string res;
        stack<string> stk;
        string word;
        for(int i = 0; i < s.size(); i++){
            if(s[i]!=' ') word+=s[i];
            else if(word!=""){
                stk.push(word);
                word = "";
            }
        }
        if(word!= "") stk.push(word);
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
            if(!stk.empty()) res+=' ';
        }
        return res;
    }
};