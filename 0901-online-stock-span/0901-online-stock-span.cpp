#include <stack>
#include <utility> // for pair

class StockSpanner {
    stack<pair<int, int>> prices; // Pair of price and its span
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1; // Default span for the current day
        
        // Check if the stack is not empty and the previous prices are less than or equal to the current price
        while (!prices.empty() && prices.top().first <= price) {
            span += prices.top().second; // Add the span of the previous price to the current span
            prices.pop(); // Remove the previous price
        }
        
        prices.push({price, span}); // Push the current price and its span into the stack
        return span; // Return the span for the current day
    }
};