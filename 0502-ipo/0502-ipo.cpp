#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalHeap;
        priority_queue<int> maxProfitHeap;
        for (int i = 0; i < profits.size(); ++i) {
            minCapitalHeap.push({capital[i], profits[i]});
        }
        for (int i = 0; i < k; ++i) {
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= w) {
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }
            
            // If no projects can be started, break the loop
            if (maxProfitHeap.empty()) {
                break;
            }
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        
        return w;
    }
};