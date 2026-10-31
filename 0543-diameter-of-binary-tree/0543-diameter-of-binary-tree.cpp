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
    int count(TreeNode* root){
        if(root==NULL)
            return 0;
        return 1+ max(count(root->left),count(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int leftdia=diameterOfBinaryTree(root->left);
        int rightdia=diameterOfBinaryTree(root->right);
        int height=count(root->left)+count(root->right);
        int maxi=max(leftdia,rightdia);
        return max(maxi,height);
    }
};