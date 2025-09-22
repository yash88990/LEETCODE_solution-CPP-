#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> countMap;
        for (int num : arr) {
            countMap[num]++;
        }
        
        std::unordered_set<int> uniqueCounts;
        for (const auto& pair : countMap) {
            if (uniqueCounts.find(pair.second) != uniqueCounts.end()) {
                return false;
            }
            uniqueCounts.insert(pair.second);
        }
        
        return true;
    }
};