#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Min-heap to keep projects based on the capital required to start them
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalHeap;
        
        // Max-heap to keep track of the maximum profit projects that can be started with current capital
        priority_queue<int> maxProfitHeap;
        
        // Push all projects into the min-heap based on their capital requirements
        for (int i = 0; i < profits.size(); ++i) {
            minCapitalHeap.push({capital[i], profits[i]});
        }
        
        // Process up to k projects
        for (int i = 0; i < k; ++i) {
            // Move all projects that can be started with current capital to the max-heap
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= w) {
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }
            
            // If no projects can be started, break the loop
            if (maxProfitHeap.empty()) {
                break;
            }
            
            // Select the project with the maximum profit
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        
        return w;
    }
};