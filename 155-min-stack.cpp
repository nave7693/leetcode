// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        main.push(x);
        if (mins.empty() || x <= mins.top()) {
            mins.push(x);
        }
    }
    
    void pop() {
        int last = main.top();
        main.pop();
        if (!mins.empty() && last == mins.top()) {
            mins.pop();
        }
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return mins.top();
    }
    
    stack<int> main;
    stack<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */