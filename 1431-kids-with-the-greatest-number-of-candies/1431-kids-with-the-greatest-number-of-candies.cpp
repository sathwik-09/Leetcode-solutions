class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> v;
        int maxi=INT_MIN;
        for(int i=0; i<candies.size();i++){
            if(candies[i]>maxi){
                maxi=candies[i];
            }
        }
        for(int i=0; i<candies.size(); i++){
            candies[i]+=extraCandies;
            if(candies[i]>=maxi){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
        }
        return v;
    }
};