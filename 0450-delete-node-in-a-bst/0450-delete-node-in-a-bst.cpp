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
private:
TreeNode* minval(TreeNode* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
           
            if(!root->left and !root->right){
                delete root;
                root = NULL;
                return NULL;
            }
            
            if(root->left and !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(!root->left and root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->left and root->right){  
                int mini = minval(root->right) -> val;
                root->val = mini;
                root->right = deleteNode(root->right , mini);
                return root;
            }
        }
        if(key < root->val){
            root->left = deleteNode(root->left , key);
            }
            if(key > root->val){
            root->right = deleteNode(root->right , key);
          }
        return root;
        } 

};
