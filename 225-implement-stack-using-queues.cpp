// https://leetcode.com/problems/implement-stack-using-queues/

class Stack {
public:
    // The front of the queue is the top of the stack

    // Push element x onto stack.
    void push(int x) {
        deque<int> temp;
        temp.push_back(x);
        while (!queue.empty()) {
            temp.push_back(queue.front());
            queue.pop_front();
        }
        while (!temp.empty()) {
            queue.push_back(temp.front());
            temp.pop_front();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        queue.pop_front();
    }

    // Get the top element.
    int top() {
        return queue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue.empty();
    }
    
private:
    deque<int> queue;
};