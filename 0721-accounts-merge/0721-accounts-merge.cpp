
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        //Connecting nodes , making ultimate parents
        unordered_map<string,int> mailToNode;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mailToNode.find(mail) == mailToNode.end()){
                    mailToNode[mail] = i;
                }
                else{
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }
        
        // Merging mails according to disjoint set data
        vector<string> mergeMails[n];
        for(auto it : mailToNode){
            string mail = it.first;
            int node = ds.findUltParent(it.second);
            mergeMails[node].push_back(mail);
            
        }
        // Rearranging
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergeMails[i].size()==0) continue;
            sort(mergeMails[i].begin(), mergeMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};