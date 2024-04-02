class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> mpp1;
        unordered_map<char, char> mpp2;
        for (int i = 0; i < n; i++) {
            if (mpp1[s[i]]==0 && mpp2[t[i]]==0) {
                mpp1[s[i]] = t[i];
                mpp2[t[i]] = s[i];
            }
            else {
                if (mpp1[s[i]]!=t[i] || mpp2[t[i]]!=s[i]) return false;
            }
        }

        return true;
    }
};