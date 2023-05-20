class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> distance(n,vector<int> (m,1e9));
        distance[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0 , {0,0}});
        
        int dr[] = {-1,0, +1,0};
        int dc[] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto  it = pq.top();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
        
            
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                
                if(nr>=0 && nr<n and nc>=0 and nc<m){
                    int effort = max(abs(heights[row][col] - heights[nr][nc]) , dist);
                    if(effort < distance[nr][nc]){
                        distance[nr][nc] = effort;
                        pq.push({effort , {nr,nc}});
                    }
                }
            }
        }
        return distance[n-1][m-1];
    }
};