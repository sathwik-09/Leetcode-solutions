class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0),outdegree(n+1,0);
        for(auto v:trust){
            outdegree[v[0]]++;
            indegree[v[1]]++;
        }
        for(int i=1; i<=n; i++){
            if(indegree[i]==n-1 && outdegree[i]==0) return i;
        }
        return -1;
    }
};