class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int i=0; i<=amount; i++){
            prev[i] = (i%coins[0]==0) ;
        }
        for(int index=1; index<n; index++){
            for(int target=0; target<=amount; target++){
                long long exclude = prev[target];
                long long include = 0;
                if(coins[index]<=target) include = curr[target-coins[index]];
                curr[target]=include+exclude;
            }
            prev=curr;
        }
        return prev[amount];
    }
};