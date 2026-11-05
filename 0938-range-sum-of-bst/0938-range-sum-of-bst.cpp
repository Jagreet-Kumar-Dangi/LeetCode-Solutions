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
    int sum(TreeNode* root,int low,int high){
        if(root==NULL)
            return 0;
        int leftans=sum(root->left,low,high);
        int rightans=sum(root->right,low,high);
        if(root->val<=high && root->val>=low)
            return leftans+rightans+root->val;
        else
            return leftans+rightans;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sum(root,low,high);
    }
};