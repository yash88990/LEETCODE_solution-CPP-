#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        // Step 1: Count the degree of each city
        std::vector<int> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // Step 2: Sort cities by their degree
        std::vector<int> cities(n);
        for (int i = 0; i < n; ++i) {
            cities[i] = i;
        }
        std::sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });
        
        // Step 3: Assign values to cities
        std::vector<int> value(n, 0);
        for (int i = 0; i < n; ++i) {
            value[cities[i]] = n - i;
        }
        
        // Step 4: Calculate the total importance
        long long total_importance = 0;
        for (const auto& road : roads) {
            total_importance += value[road[0]] + value[road[1]];
        }
        
        return total_importance;
    }
};
