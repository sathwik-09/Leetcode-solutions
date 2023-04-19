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
    int cnt=0;
    int countNodes(TreeNode*root,int prev){
        if(root==NULL)return 0;
        if(prev<=root->val){
            cnt++;
        }
        countNodes(root->left,max(prev,root->val));
        countNodes(root->right,max(prev,root->val));
        return cnt;

    }
    int goodNodes(TreeNode* root) {
        return countNodes(root,INT_MIN);
    }
};