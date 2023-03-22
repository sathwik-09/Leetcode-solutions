class Solution {
public:
    int findPosition (vector<int> nums2, int key)
    {
        int n = nums2.size() ; 
        for (int i = 0 ; i < n ; i ++)
        {
            if (nums2[i] == key)
            {
                return i ; 
            }
        }
        return -1 ; 
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans ; 
        for (int i = 0 ; i < nums1.size() ; i ++)
        {
            int element = nums1[i] ; 
            int val = -1 ; 
            int position = findPosition(nums2, element) ; 
            for (int j = position + 1 ; j < nums2.size() ; j ++)
            {
                if (nums2[j] > element)
                {
                    val = nums2[j] ; 
                    break ; 
                }
                else continue ; 
            }
            ans.push_back(val) ; 
        }
        return ans ; 
    }
};
