class Solution {
private:
    void dfs(int val, vector<vector<int>>& isConnected, vector<int> &visited){
        visited[val]=1;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[val][i] && !visited[i]){
                dfs(i,isConnected,visited);
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
                dfs(i,isConnected,visited);
            }
        }
        return cnt;
        
    }
};