class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front2(2,0);
        vector<int> front1(2,0);
        vector<int> curr(2,0);
        for(int index=n-1;index>=0;index--){
            curr[1] = max(-prices[index]+front1[0], front1[1]);
            curr[0] = max(prices[index]+front2[1], front1[0]);
            front2=front1;
            front1=curr;
        }
        return curr[1];
    }
};