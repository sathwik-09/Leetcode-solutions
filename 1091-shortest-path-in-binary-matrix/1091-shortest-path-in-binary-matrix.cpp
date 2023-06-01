class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        
        queue<pair<int, pair<int,int>>> q; 
        q.push({1, {0, 0}});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int distance = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == n-1 && col == n-1) return distance;
            
            //for iterating all 8 directions
            for(int drow = -1; drow<=1; drow++)
            {
                for(int dcol = -1; dcol<=1; dcol++)
                {
                    int newr = row + drow;
                    int newc = col + dcol;
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc] == 0 && !vis[newr][newc])
                    {
                        vis[newr][newc] = 1;
                        q.push({distance+1, {newr,newc}});
                    }
                }
            }
        }
        
        return -1;
    }
};