#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        // Step 1: Sort the citations in descending order
        std::sort(citations.begin(), citations.end(), std::greater<int>());
        
        int h_index = 0;
        
        // Step 2: Iterate through the sorted list and find the maximum h
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] >= i + 1) {
                h_index = i + 1;
            } else {
                break;
            }
        }
        
        return h_index;
    }
};