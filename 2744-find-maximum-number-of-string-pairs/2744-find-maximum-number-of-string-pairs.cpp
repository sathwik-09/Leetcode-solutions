class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int ans = 0;
        for(auto i : words){
            string rev = i;
            reverse(rev.begin(), rev.end());
            if(s.find(rev) == s.end())
                s.insert(i);
            else
                ans++;
        }
        return ans;
    }
};