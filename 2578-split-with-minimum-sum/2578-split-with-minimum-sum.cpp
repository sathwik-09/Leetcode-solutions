class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string n1 = "";
        string n2 = "";
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                n1 += s[i];
            }else{
                n2 += s[i];
            }
        }
        int sum1 = stoi(n1);
        int sum2 = stoi(n2);
        int sum = sum1 + sum2;
        return sum;
    }
};