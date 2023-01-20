class MyStack {
public:
    stack<int>s;
    MyStack() {
        
    }
    
    void push(int x) 
    {
       s.push(x); 
    }
    
    int pop() {
        int temp;
        if(s.size()==0)
            return -1;
        else
        {
         temp=s.top();
            s.pop();
        }
        return temp;
        
    }
    
    int top() {
        if(s.size()==0)
            return -1;
        else
        {
            return s.top();
         }
    }
    
    bool empty() 
    {
    if(s.size()==0)
        return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */