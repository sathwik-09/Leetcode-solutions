class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char, int> mpp;
        for(char ch : s) {
            mpp[ch]++;
            if (mpp[ch] % 2 == 1)
                oddCount++;
            else    
                oddCount--;
        }
        if (oddCount > 1)
            return s.length() - oddCount + 1;
        return s.length();
    }
};