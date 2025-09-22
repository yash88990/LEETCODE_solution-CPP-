#include <vector>
#include <stack>
#include <cmath>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> asteroidStack;
        
        for (int asteroid : asteroids) {
            if (asteroid > 0) { // Moving to the right
                asteroidStack.push(asteroid);
            } else { // Moving to the left
                while (!asteroidStack.empty() && asteroidStack.top() > 0 && asteroidStack.top() < std::abs(asteroid)) {
                    asteroidStack.pop();
                }
                
                if (asteroidStack.empty() || asteroidStack.top() < 0) {
                    asteroidStack.push(asteroid);
                } else if (asteroidStack.top() == std::abs(asteroid)) {
                    asteroidStack.pop();
                }
            }
        }
        
        std::vector<int> result(asteroidStack.size());
        for (int i = asteroidStack.size() - 1; i >= 0; --i) {
            result[i] = asteroidStack.top();
            asteroidStack.pop();
        }
        
        return result;
    }
};