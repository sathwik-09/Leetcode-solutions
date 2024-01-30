class Solution {
public:
    long long flowerGame(int n, int m) {
        long long evenX = n/2;
        long long oddX = (n+1)/2;
        long long evenY = m/2;
        long long oddY = (m+1)/2;
        long long ans = oddX*evenY + evenX*oddY;
        return ans;
        // simply return n*m/2;
    }
};