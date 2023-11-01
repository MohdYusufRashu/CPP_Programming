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
    
    void helper(TreeNode* root,vector<int>& output,int& modecount,int& count,int& last){
        if(root==NULL){
            return ;
        }
        helper(root->left,output,modecount,count,last);
        if(output.size()==0){
            output.push_back(root->val);
            modecount=1;
            count=1;
        }else{
            if(root->val==last){
                count++;
            }else{
                count=1;
            }
            if(count==modecount){
                output.push_back(root->val);
            }else if(count>modecount){
                output.clear();
                output.push_back(root->val);
                modecount=count;
            }
        }
        last=root->val;
        helper(root->right,output,modecount,count,last);
        
        
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> output;
        int modecount=0;
        int count=0;
        int last=INT_MIN;
        helper(root,output,modecount,count,last);
        return output;
    }
};