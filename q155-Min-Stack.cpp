q155-Min-Stack

/*

  Using two stacks to maintain the data and minvalue seperately.

E.g.
  
Push Sequence
-3, -5, -1, 0, 1, 2, -5

Stack Status

Bottom <--> Top 
Data: -3, -5
MinV: -3, -5

Data: -3, -5, -5
MinV: -3, -5, -1, 0, 1, 2, -5

*/

class MinStack {
    
    stack<int> data;
    stack<int> min;
    
public:
    MinStack() {
        data = stack<int>();
        min = stack<int>();
    }
    
    void push(int val) {
        
        data.push(val);
        if(min.empty() || val <= min.top())
            min.push(val);
    }
    
    void pop() {
        if(data.top() <= min.top())
            min.pop();
        data.pop();
        
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */