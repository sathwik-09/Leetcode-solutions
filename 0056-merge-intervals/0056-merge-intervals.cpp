class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for(auto intervals : intervals){
            if(output.empty() || output.back()[1] < intervals[0]){
                output.push_back(intervals);
            }
            else{
                output.back()[1] = max(output.back()[1], intervals[1]);
            }
        }
        return output;
        
    }
};