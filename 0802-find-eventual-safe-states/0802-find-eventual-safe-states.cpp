class Solution {
public:
  bool dfs(int node,vector<int> &path,vector<int> &visited,vector<int> &check,vector<int> adj[]){
      visited[node]=1;
      path[node]=1;
      for(auto i:adj[node]){
          if(visited[i]==0 && path[i]==0){
              if(dfs(i,path,visited,check,adj)==true){
                  return true;
              }
          }
          else if(visited[i]==1 && path[i]==1){
                  return true;
              }
      }
      path[node]=0;
      check[node]=1;
      return false;
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size(); 
        vector<int> adj[V];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> visited(V,0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(i,path,visited,check,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};