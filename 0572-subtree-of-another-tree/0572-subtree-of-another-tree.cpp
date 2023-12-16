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
    
    bool helper(TreeNode* root, TreeNode* subRoot,bool immediate){
        if(root==NULL){
            if(subRoot==NULL){
                return true;
            }
            return false;
        }
        if(subRoot==NULL) return false;
        if(immediate){
            if(root->val==subRoot->val){
               return helper(root->left,subRoot->left,true) && helper(root->right,subRoot->right,true);
            }else{
                return false;
            }
        }
        bool ans=false;
        ans=helper(root->left,subRoot,false) || helper(root->right,subRoot,false);
        if(root->val==subRoot->val){
            ans=ans || (helper(root->left,subRoot->left,true) && helper(root->right,subRoot->right,true));
        }
        return ans;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot,false);
    }
};