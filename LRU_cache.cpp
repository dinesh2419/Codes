class LRUCache {
public:
    class Node
    {
        public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int _key,int _value)
        {
            key=_key;
            value=_value;
            Node* prev=NULL;
            Node* next=NULL;
        }
    };
    
    int count=0;
    int size;
    map<int,Node*>m;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
    void addnode(Node* temp)
    {
        temp->next=head->next;
        head->next->prev=temp;
        temp->prev=head;
        head->next=temp;
    }
    
    
    void deletenode(Node* temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    
    
    
    
    LRUCache(int capacity) 
    {
       size=capacity;
       head->next=tail;
       tail->prev=head; 
    }
    
    
    int get(int key) 
    {
         if(m.count(key)==0)
         {
             return -1;
         }
             Node* current=m[key];
             int ans=current->value;
             m.erase(key);
             deletenode(current);         
             addnode(current);
             m[key]=head->next;
             return ans;
    }
    
    void put(int key, int value) 
    {
        if(m.count(key)==1)
        {
           Node* current=m[key];
           deletenode(current);
           m.erase(key);
           addnode(new Node(key,value));
           m[key]=head->next;
           return;
        }
        if(m.size()<size)
        {
            Node* current=new Node(key,value);
            addnode(current);
            m[key]=head->next;
            
        }
        else
        {
            int var=tail->prev->key;
            deletenode(m[var]);
            m.erase(var);
             Node* ms=new Node(key,value);
            addnode(ms);
            m[key]=head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
