#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int, int> countMap;
        std::vector<int> result;

        // Count the occurrences of each element in arr1
        for (int num : arr1) {
            countMap[num]++;
        }

        // Add elements of arr2 to result in the specified order
        for (int num : arr2) {
            while (countMap[num] > 0) {
                result.push_back(num);
                countMap[num]--;
            }
            countMap.erase(num); // Remove the element from the map after processing
        }

        // Collect remaining elements not in arr2
        std::vector<int> remaining;
        for (const auto& pair : countMap) {
            for (int i = 0; i < pair.second; i++) {
                remaining.push_back(pair.first);
            }
        }

        // Sort the remaining elements and add to result
        std::sort(remaining.begin(), remaining.end());
        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;
    }
};
