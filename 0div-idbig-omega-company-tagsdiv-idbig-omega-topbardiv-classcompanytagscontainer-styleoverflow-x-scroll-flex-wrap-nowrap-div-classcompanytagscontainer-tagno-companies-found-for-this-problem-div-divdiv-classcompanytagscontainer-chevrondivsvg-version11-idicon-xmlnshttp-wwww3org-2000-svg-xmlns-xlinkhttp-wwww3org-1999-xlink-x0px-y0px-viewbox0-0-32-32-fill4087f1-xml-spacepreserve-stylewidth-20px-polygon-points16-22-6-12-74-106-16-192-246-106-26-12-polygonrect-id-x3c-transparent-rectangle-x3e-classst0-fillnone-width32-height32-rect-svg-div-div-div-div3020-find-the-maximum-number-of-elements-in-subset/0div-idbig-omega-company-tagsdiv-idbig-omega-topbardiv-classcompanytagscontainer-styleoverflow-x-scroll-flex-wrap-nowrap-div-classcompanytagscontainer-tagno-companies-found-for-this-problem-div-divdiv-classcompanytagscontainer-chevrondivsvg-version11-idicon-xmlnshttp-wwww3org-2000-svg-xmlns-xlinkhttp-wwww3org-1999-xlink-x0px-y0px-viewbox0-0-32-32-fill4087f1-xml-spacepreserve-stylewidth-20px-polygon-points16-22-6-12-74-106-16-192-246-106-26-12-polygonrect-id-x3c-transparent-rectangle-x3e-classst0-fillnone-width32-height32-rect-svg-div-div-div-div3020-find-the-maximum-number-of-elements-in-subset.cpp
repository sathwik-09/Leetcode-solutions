#define ll long long
class Solution {
public:
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
    }
};