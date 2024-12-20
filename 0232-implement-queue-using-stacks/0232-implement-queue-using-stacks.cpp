#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1; // Main stack
    stack<int> s2; // Helper stack

public:
    MyQueue() {
        // Constructor mein kuch nahi karna
    }

    void push(int x) {
        // Naya element main stack (s1) mein daalo
        s1.push(x);
    }

    int pop() {
        // Front element ko remove karne ke liye helper stack ka use karo
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int frontElement = s2.top();
        s2.pop();
        return frontElement;
    }

    int peek() {
        // Front element ko dekhne ke liye helper stack ka use karo
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        // Check karo ki dono stacks empty hain ya nahi
        return s1.empty() && s2.empty();
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
