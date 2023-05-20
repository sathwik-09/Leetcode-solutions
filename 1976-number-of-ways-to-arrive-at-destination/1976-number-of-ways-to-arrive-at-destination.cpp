class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long>>> pq;
        vector<long long> distance(n,1e12);
        vector<long long> ways(n,0);
        distance[0] = 0;
        ways[0] =1;
        int mod = (int)(1e9+7);
        pq.push({0,0});
        while(!pq.empty()){
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                if(dist+weight < distance[adjNode]){
                    distance[adjNode] = dist+weight;
                    pq.push({dist+weight,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist + weight ==distance[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};