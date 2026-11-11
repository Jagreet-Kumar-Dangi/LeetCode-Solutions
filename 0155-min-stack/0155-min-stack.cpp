class MinStack {
public:
    stack<int> s;
    stack<int> mini;
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(mini.size()==0 || value<=mini.top())
            mini.push(value);
    }
    
    void pop() {
        if(s.top()==mini.top())
            mini.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */