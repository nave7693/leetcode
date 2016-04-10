// https://leetcode.com/problems/implement-queue-using-stacks/

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> temp;
        while (!mystack.empty()) {
            temp.push(mystack.top());
            mystack.pop();
        }
        mystack.push(x);
        while (!temp.empty()) {
            mystack.push(temp.top());
            temp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        mystack.pop();
    }

    // Get the front element.
    int peek(void) {
        return mystack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return mystack.empty();
    }
private:
    stack<int> mystack; // front of the queue is top of the stack
};