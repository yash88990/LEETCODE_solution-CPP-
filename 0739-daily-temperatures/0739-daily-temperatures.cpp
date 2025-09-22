#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0); // Initialize the answer array with 0s
        stack<int> st; // Stack to store indices of temperatures
        
        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current temperature is greater than the temperature at the index at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top(); // Get the index of the temperature at the top of the stack
                st.pop(); // Pop the index from the stack
                answer[prevIndex] = i - prevIndex; // Update the answer for the previous index
            }
            st.push(i); // Push the current index onto the stack
        }
        
        return answer;
    }
};