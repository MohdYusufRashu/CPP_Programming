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
    
    pair<bool,pair<long long,long long>> helper(TreeNode* root){
        if(root==NULL){
            long long mi=INT_MAX;
            long long ma=INT_MIN;
            return {true,{mi+1,ma-1}};
        }
        if(root->left==NULL && root->right==NULL){
            return {true,{root->val,root->val}};
        }
        pair<bool,pair<long long,long long>> left=helper(root->left);
        pair<bool,pair<long long,long long>> right=helper(root->right);
        bool flag=left.first && right.first && (root->val>left.second.second) && (root->val<right.second.first);
        
        long long minVal=left.second.first;
        if(minVal>root->val){
            minVal=root->val;
        }
        
        long long maxVal=right.second.second;
        if(maxVal<root->val){
            maxVal=root->val;
        }
        
        return {flag,{minVal,maxVal}};
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root).first;
    }
};