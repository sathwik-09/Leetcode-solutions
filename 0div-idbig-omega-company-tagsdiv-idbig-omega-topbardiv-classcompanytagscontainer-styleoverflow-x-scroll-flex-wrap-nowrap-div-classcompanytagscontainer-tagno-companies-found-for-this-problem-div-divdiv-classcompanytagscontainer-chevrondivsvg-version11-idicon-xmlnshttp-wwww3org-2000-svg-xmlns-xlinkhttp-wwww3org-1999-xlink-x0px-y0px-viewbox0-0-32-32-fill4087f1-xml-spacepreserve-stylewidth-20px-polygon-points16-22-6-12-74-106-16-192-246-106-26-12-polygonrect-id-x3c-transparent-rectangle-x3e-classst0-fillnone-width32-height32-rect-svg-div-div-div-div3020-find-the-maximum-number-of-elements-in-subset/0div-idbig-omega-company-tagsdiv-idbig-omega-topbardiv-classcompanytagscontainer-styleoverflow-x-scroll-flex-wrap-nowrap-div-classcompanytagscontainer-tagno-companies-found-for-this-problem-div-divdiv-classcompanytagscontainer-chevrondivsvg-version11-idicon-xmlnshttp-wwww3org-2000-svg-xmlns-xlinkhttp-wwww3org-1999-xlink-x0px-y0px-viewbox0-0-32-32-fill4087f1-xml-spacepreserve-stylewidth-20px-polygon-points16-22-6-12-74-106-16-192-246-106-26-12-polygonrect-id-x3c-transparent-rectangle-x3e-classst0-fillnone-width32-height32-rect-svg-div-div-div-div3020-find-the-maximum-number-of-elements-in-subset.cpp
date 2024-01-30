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
                if(mpp[x] < 2){
                    sz += mpp[x];
                    mpp[x] = 0;
                    break;
                }
                sz += 2;
                mpp[x] -= 2;
                x *= x;
            }
            //If answer is even then subract 1 as size would be odd means deleting the max number which occured twice
            ans=max(ans,sz-(sz%2==0));
        }
        return ans;
    }
};



/*
int maximumLength(vector<int>& nums) {
        long long n = nums.size();
        map<long long, long long> mp;
        for(auto i: nums) mp[i]++;
        sort(nums.begin(), nums.end());
        long long mx = 1;
        for(int i=0; i<n; i++){
            long long cur = nums[i];
            long long cur_max = 0;
            while(mp[cur]){
                if(mp[cur] < 2){
                    cur_max += mp[cur];
                    mp[cur] = 0;
                    break;
                }
                cur_max += 2;
                mp[cur] -= 2;
                cur *= cur;
            }
            if(cur_max % 2 == 0){
                mx = max(mx, cur_max - 1);
            }
            else mx = max(mx, cur_max);
        }
        
        return mx;
        */