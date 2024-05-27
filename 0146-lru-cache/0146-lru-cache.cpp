
class Node{
    public:
    int val;
    int key;
    Node* prev;
    Node* next;
    Node(int _key,int _val){
        val=_val;
        key=_key;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    unordered_map<int,Node*> map;
    int capacity;
    
    LRUCache(int capacity) {
        head=NULL;
        tail=NULL;
        this->capacity=capacity;
    }
    
    void gethelper(Node* curr){
        if(curr==head) return;
        if(curr==tail) tail=tail->prev;
        if(curr->next) curr->next->prev=curr->prev;
        if(curr->prev) curr->prev->next=curr->next;
        curr->next=head;
        curr->prev=NULL;
        head->prev=curr;
        
        head=curr;
    }
    
    void insert(int key,int value){
        Node* curr=new Node(key,value);
        map[key]=curr;
        curr->next=head;
        if(head) head->prev=curr;
        else tail=curr;
        head=curr;
    }
    
    int get(int key) {
        
        if(map.find(key)==map.end()) return -1;
        Node* curr=map[key];
        int ans=curr->val;
        gethelper(curr);
        return ans;
    }
    
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            map[key]->val=value;
            gethelper(map[key]);
        }else{
            if(map.size()<capacity){
                insert(key,value);
            }else{
                //evict last
                map.erase(tail->key);
                Node* temp=tail;
                if(tail->prev) tail->prev->next=NULL;
                tail=tail->prev;
                if(tail==NULL) head=NULL;
                delete temp;
                insert(key,value);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */