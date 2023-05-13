class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        int visited[n][m];
        int freshCount=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                else{
                    visited[i][j] = 0;
                }
                if(grid[i][j]==1) freshCount++;
            }
        }
        
        int timer=0;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,1,0,-1};
        int cnt = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            timer = max(timer,t);
            q.pop();
            for(int i=0; i<4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && visited[newRow][newCol]==0 && grid[newRow][newCol]==1){
                    q.push({{newRow,newCol}, t+1});
                    visited[newRow][newCol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=freshCount) return -1;
        return timer;
        
    }
};