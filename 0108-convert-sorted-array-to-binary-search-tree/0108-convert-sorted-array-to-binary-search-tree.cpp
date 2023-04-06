/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int s , int e , vector<int>&ans ){
        if(s>e){
            return NULL;
        }
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = solve(s , mid-1 ,ans);
        root->right= solve(mid+1 , e , ans);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};