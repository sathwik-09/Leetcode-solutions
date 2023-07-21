class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        for(int ind = n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int maxi=1; maxi<=k; maxi++){
                    if(buy){
                        curr[buy][maxi]=max(-prices[ind]+after[0][maxi],
                                               after[1][maxi]);
                    }
                    else curr[buy][maxi] = max((prices[ind]+after[1][maxi-1]), after[0][maxi]);
                }
            }
            after = curr;
        }
        return after[1][k];
    }
};