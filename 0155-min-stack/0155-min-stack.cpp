class MinStack {
public:
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.size()==0)
            s.push({value,value});
        else{
            int mini=min(value,s.top().second);
            s.push({value,mini});
        }
    }
    
    void pop() {
        return s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
        
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