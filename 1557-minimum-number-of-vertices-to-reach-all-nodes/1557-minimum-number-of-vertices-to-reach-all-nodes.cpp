class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        for(auto it:edges){
            visited[it[1]] = 1;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};