class Solution {
private:
    vector<int> dijkstra(vector<pair<int, int>> adj[], int n, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> temp(n, INT_MAX);
        temp[src] = 0;
        pq.push({0, src});
        while(!pq.empty()) {
            int prevNode = pq.top().second;
            int prevDist = pq.top().first;
            pq.pop();
            for(auto it:adj[prevNode]) {
                int currNode = it.first;
                int currDist = it.second;
                if(currDist + prevDist < temp[currNode]) {
                    temp[currNode] = currDist+prevDist;
                    pq.push({temp[currNode], currNode});
                }
            }
        }
        return temp;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n];
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        for(auto it:edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        for(int i=0; i<n; i++) {
            dist[i] = dijkstra(adj, n, i);
        }
        int cityNo = -1;
        int cityCnt = n;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(dist[i][j] <= distanceThreshold) cnt++;
            }
            if(cityCnt >= cnt) {
                cityCnt = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};