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
    void solve(unordered_map<int,int>&mp,TreeNode* root){
        if(root == NULL){
            return;
        }
        mp[root->val]++;
        solve(mp,root->left);
        solve(mp,root->right);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        solve(mp,root);
        int mini = INT_MIN;
        vector<int> ans;
        for(auto temp:mp){
            if(temp.second>mini){
                mini = temp.second;
            }
        }
        for(auto hemp:mp){
            if(hemp.second==mini){
                ans.push_back(hemp.first);
            }
        }
        return ans;
    }
};