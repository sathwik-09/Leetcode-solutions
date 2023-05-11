class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& grid){
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //Traverse the neighbours and mark them as visited if it's a land
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(i)==abs(j)) continue;
                    int newr = row + i;
                    int newc = col + j;
                    if(newr>=0 && newr<n && newc>=0 && newc<m && 
                       grid[newr][newc]=='1' && visited[newr][newc]==0)
                    {
                        q.push({newr,newc});
                        visited[newr][newc]=1;
                    }
                }
            }
                
            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    bfs(row,col,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};