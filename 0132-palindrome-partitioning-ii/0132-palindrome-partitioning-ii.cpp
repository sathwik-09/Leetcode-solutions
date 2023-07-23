class Solution {
private:
    /*
    int solve(int i, int n, string& s, vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int cost = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalin(i, j, s)){
                int cut = 1 +  solve(j+1, n, s, dp);
                cost = min(cut, cost);
            }
        }
        return dp[i] = cost;
    }
    */
public:
    bool isPalin(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n-1]=0;
        for(int i=n-1; i>=0; i--){
            int cost = INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalin(i,j,s)){
                    int cut = 1 + dp[j+1];
                    cost = min(cut, cost);
                }
            }
            dp[i] = cost;
        }
        return dp[0]-1;
    }
};