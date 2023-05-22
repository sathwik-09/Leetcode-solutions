class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n,1e7));
        for(auto it:edges){
            distance[it[0]][it[1]] = it[2];
            distance[it[1]][it[0]] = it[2];
        }
        for(int i=0; i<n; i++){
           distance[i][i]=0; 
        }  
        for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
	            }
	        }
	    }
	    int nc = n;
        int city = 0;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(distance[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=nc){
                city = i;
                nc = count;
            }
        }
        return city;
    }
};