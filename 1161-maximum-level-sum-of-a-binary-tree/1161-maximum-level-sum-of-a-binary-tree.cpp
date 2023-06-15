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
    int maxLevelSum(TreeNode* root) {
        int ans=0;
        int maxSum=-1e9;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int siz= q.size();
            level++;
            long currsum=0;
            for(int i=0; i<siz; i++){
                TreeNode* node= q.front();
                q.pop();
                currsum+= node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }   
            }
             if(currsum>maxSum){
                    ans=level;
                    maxSum= currsum;
                    
            }
        }
        return ans;
    }
};