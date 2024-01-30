#define ll long long
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=0;
        // used map for sorting the frequencies to figure out that lowest numbers can be taken first
        map<ll , int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto [el,freq]:mpp){
            ll x=el;
            int sz=0;
            while(mpp.find(x)!=mpp.end() && mpp[x]){
                // edge case if elememnt=1 then add all the occurences of 1
                if(x==1) sz+=mpp[1];
                else if(mpp[x]>=2) sz+=2;
                // if freq of el is 1 then simply increase cnt and break cause there will no more occurences
                else if(mpp[x]==1){
                    sz+=1;
                    break;
                }
                // after adding occurences make it zero as those will be no use
                mpp[x]=0;
                if(x>1e5) break;
                //for the next pass it keeps on increasing by raising of power 2
                x=x*x;
            }
            //If answer is even then subract 1 as size would be odd means deleting the max number which occured twice
            ans=max(ans,sz-(sz%2==0));
        }
        return ans;
    }
};