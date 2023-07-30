class Solution {
public:
    int solve(int i, int j,int m,int n,vector<vector<int>>& dungeon,vector<vector<int>> &dp){
        if(i >= m+1 or j >= n+1) return 1e9;
        if(i==m && j==n){
            if(dungeon[i][j]>0) return 1;
            else return 1-dungeon[i][j];
        };
        if(dp[i][j]!=-1) return dp[i][j];
        int down = solve(i+1,j,m,n,dungeon,dp);
        int right = solve(i,j+1,m,n,dungeon,dp);
        int res= min(down,right)-dungeon[i][j];
        if(res>0) return dp[i][j] = res;
        else return dp[i][j] =1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m-1,n-1,dungeon,dp);
    }
};