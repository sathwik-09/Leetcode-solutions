class Solution {
private:
    void bfs(int val, vector<vector<int>>& isConnected, vector<int> &visited){
        queue<int> q;
        q.push(val);
        visited[val]=1;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[val][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> visited(n);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cnt++;
                bfs(i,isConnected,visited);
            }
        }
        return cnt;
        
    }
};