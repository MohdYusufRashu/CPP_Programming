class WordDictionary {
public:
    
    class Node{
        public:
        char data;
        vector<Node*> children;
        bool isTerminal;
        
        Node(char _data){
            data=_data;
            children.resize(26,NULL);
            isTerminal=false;
        }
    };
    
    Node* root;
    WordDictionary() {
        root=new Node('\0');
    }
    
    void insertHelper(Node* root,string& str,int index){
        //base case
        if(index==str.size()){
            root->isTerminal=true;
            return;
        }
        int childIndex=str[index]-'a';
        if(root->children[childIndex]!=NULL){
            insertHelper(root->children[childIndex],str,index+1);
        }else{
            Node* newnode=new Node(str[index]);
            root->children[childIndex]=newnode;
            insertHelper(newnode,str,index+1);
        }

    }
    
    void addWord(string word) {
        insertHelper(root,word,0);
    }
    
    bool searchHelper(Node* root,string& str,int index){
        
        //cout<<root->data<<" ";
        if(index==str.size()){
            return root->isTerminal;
        }
        if(str[index]=='.'){
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    if(searchHelper(root->children[i],str,index+1)) return true;
                }
                
            }
            return false;
        }
        int childIndex=str[index]-'a';
        if(root->children[childIndex]==NULL){
            return false;
        }
        return searchHelper(root->children[childIndex],str,index+1);
    }
    
    bool search(string word) {
        //cout<<endl<<word<<endl;
        return searchHelper(root,word,0);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */