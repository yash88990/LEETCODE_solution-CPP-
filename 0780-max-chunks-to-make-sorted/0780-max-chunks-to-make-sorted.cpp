#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxVal = 0; // Tracks the maximum value encountered so far
        int chunks = 0; // Count of chunks
        
        for (int i = 0; i < arr.size(); i++) {
            maxVal = max(maxVal, arr[i]); // Update the maximum value
            if (maxVal == i) { 
                // If the maximum value is equal to the current index, we can form a chunk
                chunks++;
            }
        }
        return chunks; // Return the total number of chunks
    }
};

