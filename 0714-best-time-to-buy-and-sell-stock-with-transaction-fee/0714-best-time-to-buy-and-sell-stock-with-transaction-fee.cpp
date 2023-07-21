class Solution {
public:
    /*
    int solve(int ind, int buy, vector<int>& prices, int fees){
        if(ind==prices.size()) return 0;
        int profit = 0;
        if(buy==1){
            profit=max((-prices[ind]+solve(ind+1,0,prices,fees)),solve(ind+1,1,prices,fees));
        }
        else profit = max((prices[ind]-fees+solve(ind+1,1,prices,fees)), solve(ind+1,0,prices,fees));
        return profit;
    }
    */
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<long long> front(2,0), curr(2,0);
        front[0] = front[1] = 0;
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                long long profit = 0;
                if(buy==1){
                    profit=max((-prices[ind]+front[0]),front[1]);
                }
                else profit = max((prices[ind]-fee+front[1]),front[0]);
                curr[buy] = profit;
            }
            front = curr;
        }
        return front[1];
    }
};