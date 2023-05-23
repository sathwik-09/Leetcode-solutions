class DisjointSet{
public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUltParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUltParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ultPar_u = findUltParent(u);
        int ultPar_v = findUltParent(v);
        if(ultPar_u == ultPar_v) return;
        if(size[ultPar_u] < size[ultPar_v]){
            parent[ultPar_u] = ultPar_v;
            size[ultPar_v] += size[ultPar_u];
        }
        else{
            parent[ultPar_v] = ultPar_u;
            size[ultPar_u] += size[ultPar_v];
        }
    }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUltParent(u) == ds.findUltParent(v)){
                extraEdges++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int connectedCompo = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i){
                connectedCompo++;
            }
        }
        int ans = connectedCompo - 1;
        if(extraEdges >= ans){
            return ans;
        }
        else return -1;
    }
};