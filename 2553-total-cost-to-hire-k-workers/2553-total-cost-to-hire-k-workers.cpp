#include <vector>
#include <queue>

class Solution {
public:
    long long totalCost(std::vector<int>& costs, int k, int candidates) {
        // Define two min-heaps
        std::priority_queue<int, std::vector<int>, std::greater<int>> left_heap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> right_heap;
        
        // Number of workers
        int n = costs.size();
        
        // Add initial candidates to the heaps
        for (int i = 0; i < candidates && i < n; ++i) {
            left_heap.push(costs[i]);
        }
        
        for (int i = std::max(n - candidates, candidates); i < n; ++i) {
            right_heap.push(costs[i]);
        }
        
        long long total_cost = 0;
        int left_index = candidates;
        int right_index = n - candidates - 1;
        
        // Hire k workers
        for (int i = 0; i < k; ++i) {
            int left_cost = left_heap.empty() ? INT_MAX : left_heap.top();
            int right_cost = right_heap.empty() ? INT_MAX : right_heap.top();
            
            if (left_cost <= right_cost) {
                total_cost += left_cost;
                left_heap.pop();
                if (left_index <= right_index) {
                    left_heap.push(costs[left_index++]);
                }
            } else {
                total_cost += right_cost;
                right_heap.pop();
                if (left_index <= right_index) {
                    right_heap.push(costs[right_index--]);
                }
            }
        }
        
        return total_cost;
    }
};