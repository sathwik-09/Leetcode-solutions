class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> distance(n,1e9);
        distance[src]=0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops>k) continue;
            for(auto i : adj[node]){
                int adjNode = i.first;
                int edgeWeight = i.second;
                if(cost + edgeWeight < distance[adjNode] && stops<=k){
                    distance[adjNode] = cost + edgeWeight;
                    q.push({stops+1,{adjNode,cost+edgeWeight}});
                }
            }
        }
        if(distance[dst]==1e9) return -1;
        return distance[dst];
    }
};