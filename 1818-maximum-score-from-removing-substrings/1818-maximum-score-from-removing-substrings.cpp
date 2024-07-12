class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            // Swap roles of x and y so that we always remove the more valuable pair first
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        
        int points = 0;
        points += removeAndCount(s, 'a', 'b', x);
        points += removeAndCount(s, 'b', 'a', y);
        
        return points;
    }
    
    int removeAndCount(string &s, char first, char second, int points) {
        stack<char> stk;
        int totalPoints = 0;
        
        for (char c : s) {
            if (!stk.empty() && stk.top() == first && c == second) {
                stk.pop();
                totalPoints += points;
            } else {
                stk.push(c);
            }
        }
        
        // Construct remaining string from the stack
        string remaining;
        while (!stk.empty()) {
            remaining.push_back(stk.top());
            stk.pop();
        }
        reverse(remaining.begin(), remaining.end());
        s = remaining;
        
        return totalPoints;
    }
};
