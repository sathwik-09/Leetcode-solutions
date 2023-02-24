class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int> ms;
        for(auto i : matrix){
            for(auto j : i){
                ms.insert(j);
            }
        }
        int ans;
        for(auto i : ms){
            if(k == 0) continue;
            ans = i;
            k--;
         }
         return ans;
    }
};