class Solution {
public:
    // TC:- O(n*log k)   SC:- O(k)
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<heights.size()-1; i++){
            int len = heights[i+1]-heights[i];
            if(len>0) pq.push(len);
            if(pq.size()>ladders){
                bricks-=pq.top();
                pq.pop();
            }
            if(bricks<0) return i;
        }
        return heights.size()-1;
    }
};