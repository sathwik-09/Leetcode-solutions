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
    void solve(TreeNode* root , int &ans , int level){
        if(root == NULL){
            return ;
        }
        if(root -> left == NULL && root -> right == NULL){
            ans = min(ans,level);
            return;
        }
        solve(root->left, ans,level+1);
        solve(root -> right, ans,level+1);
    }

    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans = INT_MAX;
        solve(root, ans,0);
        return ans+1;
    }
};