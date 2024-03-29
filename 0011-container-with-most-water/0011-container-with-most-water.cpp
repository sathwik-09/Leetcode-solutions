class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int maxarea=-1;
        int j=height.size()-1;
        while(i < j){
            int mini=min(height[i],height[j]);
            int area=0;
            area=min(height[i],height[j])*(j-i);
            if(mini == height[i]){
                i++;
            }
            else 
            j--;
            if(area>maxarea){
                maxarea=area;
            }
        }
        return maxarea;
    }
};