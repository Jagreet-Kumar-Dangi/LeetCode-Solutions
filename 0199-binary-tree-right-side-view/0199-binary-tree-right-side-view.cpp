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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<pair<TreeNode*,int>> q;
        map<int,int> mpp;
        q.push({root,0});
        while(q.size()>0){
            TreeNode* curr=q.front().first;
            int currh=q.front().second;
            q.pop();
            mpp[currh]=curr->val;
            if(curr->left !=NULL)
                q.push({curr->left,currh+1});
            if(curr->right !=NULL)
                q.push({curr->right,currh+1});
        }
        vector<int> ans;
        for(auto i:mpp)
            ans.push_back(i.second);
        return ans;
    }
};