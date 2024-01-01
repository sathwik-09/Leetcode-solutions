class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sz = s.size();
        if(sz == 0)  return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxi = 0;
        int cookieIndex = sz - 1;
        int childIndex = g.size() - 1;
        while(cookieIndex >= 0 && childIndex >=0){
            if(s[cookieIndex] >= g[childIndex]){
                maxi++;
                cookieIndex--;
                childIndex--;
            }
            else{
                childIndex--;
            }
        }
        return maxi;
    }
};