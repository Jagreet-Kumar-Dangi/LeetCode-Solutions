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
    int count(TreeNode* root,int cnt){
        if(root==NULL){
            return cnt;
        }
        int leftcnt=count(root->left,cnt+1);
        int rightcnt=count(root->right,cnt+1);
        return max(leftcnt,rightcnt);
    }
    int maxDepth(TreeNode* root) {
        return count(root,0);
    }
};