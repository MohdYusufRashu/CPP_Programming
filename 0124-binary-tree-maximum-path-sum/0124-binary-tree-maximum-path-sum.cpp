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
    
    int helper(TreeNode* root,int& ans){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            ans=max(ans,root->val);
            return root->val;
        }
        int left=helper(root->left,ans);
        int right=helper(root->right,ans);
        int curved=left+right+root->val;
        
        int up=root->val+max(max(0,left),max(0,right));
        ans=max(ans,max(curved,up));
        return up;
        
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
    }
};