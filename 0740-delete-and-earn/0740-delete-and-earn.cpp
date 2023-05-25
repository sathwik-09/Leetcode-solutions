class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 1e4 + 1;
        vector<int> points(n,0);
        for(int it : nums){
            points[it] += it;
        }
        int include = 0,exclude = 0;
        for(int i=0; i<n; i++){
            int pick = exclude + points[i];
            int notPick = max(include,exclude);
            include = pick;
            exclude = notPick;
        }
        return max(include,exclude);
    }
};