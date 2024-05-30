/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define pb push_back
class Codec {
    
    queue<TreeNode*> q;
    
    TreeNode* buildTree(string data){
        if(data.size()==0) return NULL;
        int i=0;
        while(i<data.size() && data[i]!=','){
            i++;
        }
        string temp=data.substr(0,i);
        int num=stoi(temp);
        //cout<<num<<" ";
        TreeNode* root=new TreeNode(num);
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                int x;
                if(i!=data.size()) i++;
                x=i;
                while(i<data.size() && data[i]!=','){
                    i++;
                }
                temp=data.substr(x,i-x);
                //cout<<i<<" "<<x<<"-->temp="<<temp<<endl;
                if(temp.size() && temp!="$"){
                    int num=stoi(temp);
                    //cout<<num<<" ";
                    TreeNode* newnode=new TreeNode(num);
                    front->left=newnode;
                    q.push(newnode);
                }
                if(i!=data.size()) i++;
                x=i;
                while(i<data.size() && data[i]!=','){
                    i++;
                }
                temp=data.substr(x,i-x);
                //cout<<i<<" "<<x<<"-->temp="<<temp<<endl;
                if(temp.size() && temp!="$"){
                    int num=stoi(temp);
                    //cout<<num<<" ";
                    TreeNode* newnode=new TreeNode(num);
                    front->right=newnode;
                    q.push(newnode);
                }
                
            }
        }
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string output;
        q.push(root);
        q.push(NULL);
        string temp=to_string(root->val);
        output+=temp;
        while(!q.empty()){
            TreeNode* front=q.front();
            
            q.pop();
            if(front==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                cout<<front->val<<" ";
                if(front->left){
                    q.push(front->left);
                    string temp=to_string(front->left->val);
                    output+="," + temp;
                }else{
                    output=output+"," + "$";
                }
                if(front->right){
                    q.push(front->right);
                    string temp=to_string(front->right->val);
                    output+="," + temp;
                }else{
                    output=output+"," + "$";
                }
            }
        }
        //cout<<output;
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return buildTree(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));