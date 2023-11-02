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
    int count;
    vector<int>solve(TreeNode *root){
        if(!root) return {0,0};
        vector<int>left=solve(root->left);
        vector<int>right=solve(root->right);
        int n=1+left[1]+right[1];
        int sum=root->val+left[0]+right[0];
        int avg=(sum)/n;
        if(avg==root->val)count++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        count=0;
        solve(root);
        return count;    
    }
};