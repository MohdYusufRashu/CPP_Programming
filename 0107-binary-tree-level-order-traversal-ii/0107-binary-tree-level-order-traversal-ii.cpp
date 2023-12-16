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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL){
            return vector<vector<int>>();
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> output;
        vector<int> temp;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(!curr){
                output.push_back(temp);
                if(!q.empty()){  
                    temp.clear();
                    q.push(NULL);
                }
            }else{
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        reverse(output.begin(),output.end());
        return output;
    }
};