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
    void path(TreeNode* root,string con,vector<string>& ans){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(con);
            return;
        }
        if(root->left)
            path(root->left,con+"->"+to_string(root->left->val),ans);
        if(root->right)
            path(root->right,con+"->"+to_string(root->right->val),ans);
                
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string con=to_string(root->val);
        path(root,con,ans);
        return ans;
        
    }
};