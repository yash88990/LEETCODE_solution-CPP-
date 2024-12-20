#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1; // Main queue
    queue<int> q2; // Helper queue

public:
    MyStack() {
        // Constructor mein kuch nahi karna
    }

    void push(int x) {
        // Element ko helper queue (q2) mein daalo
        q2.push(x);
        // Main queue ke saare elements helper queue mein daalo
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Helper queue ko main queue bana do
        swap(q1, q2);
    }

    int pop() {
        // Top element ko remove karna
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        // Top element ko return karna
        return q1.front();
    }

    bool empty() {
        // Check karo ki queue empty hai ya nahi
        return q1.empty();
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
