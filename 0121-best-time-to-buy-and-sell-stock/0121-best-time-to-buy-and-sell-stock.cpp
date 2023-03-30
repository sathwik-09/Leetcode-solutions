class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            int currProfit = prices[i]-minimum;
            ans = max(ans,currProfit);
            minimum=min(minimum,prices[i]);
        }
        return ans;
    }
};