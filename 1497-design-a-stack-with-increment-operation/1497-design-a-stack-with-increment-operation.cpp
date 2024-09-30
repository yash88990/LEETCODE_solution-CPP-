class CustomStack {
private:
    vector<int> stack;  // Main stack to store elements
    vector<int> inc;    // Auxiliary array to store increments
    int maxSize;        // Maximum size of the stack

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        // Push x onto the stack if it hasn't reached the maximum size
        if (stack.size() < maxSize) {
            stack.push_back(x);
            inc.push_back(0);  // Initialize the increment for this element as 0
        }
    }
    
    int pop() {
        // If stack is empty, return -1
        if (stack.empty()) return -1;
        
        int index = stack.size() - 1;  // Get the index of the top element
        
        // Get the value of the top element, add any increment stored for it
        int result = stack[index] + inc[index];
        
        // If there's an element below it, propagate the increment
        if (index > 0) {
            inc[index - 1] += inc[index];
        }
        
        // Remove the top element and its associated increment
        stack.pop_back();
        inc.pop_back();
        
        return result;  // Return the popped value
    }
    
    void increment(int k, int val) {
        // If k is greater than the number of elements in the stack,
        // increment only up to the number of elements present
        int limit = min(k, (int)stack.size());
        
        // Increment the first 'limit' elements by 'val'
        if (limit > 0) {
            inc[limit - 1] += val;
        }
    }
};
