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
    
    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=helper(root->left);
        int right=helper(root->right);
        if(!left) root->left=NULL;
        if(!right) root->right=NULL;
        return left+right + root->val;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        int ans=helper(root);
        if(!ans) root=NULL;
        return root;
    }
};