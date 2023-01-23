class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) 
    {
      s1.push(x);  
    }
    
    int pop() 
    {
       int del;
        if(s1.size()==0)
        return -1;
        else
        {
            while(s1.size()!=0)
            {
                int temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
             
            del=s2.top();
            s2.pop();
            while(s2.size()!=0)
            {
                int var=s2.top();
                 s2.pop();
                 s1.push(var);
            }
        }
        return del; 
    }
    
    int peek() 
    {
        int del;
        if(s1.size()==0)
        return -1;
        else
        {
            while(s1.size()!=0)
            {
                int temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
             
            del=s2.top();
           // s2.pop();
            while(s2.size()!=0)
            {
                int var=s2.top();
                 s2.pop();
                 s1.push(var);
            }
        }
        return del;  
    }
    
    bool empty() 
    {
       if(s1.size()==0)
           return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */