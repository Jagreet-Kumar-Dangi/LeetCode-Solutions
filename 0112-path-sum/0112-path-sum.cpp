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
    bool ans(TreeNode* root,int sum,int targetSum){
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL){
            if(targetSum==sum+root->val)
                return true;
            else
                return false;
        }
        bool leftans=ans(root->left,sum+root->val,targetSum);
        bool rightans=ans(root->right,sum+root->val,targetSum);
        return leftans || rightans;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return ans(root,0,targetSum);

    }
};