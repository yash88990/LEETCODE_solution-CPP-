#include <vector>
#include <algorithm>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;

        // Count the total number of 1's in the array
        for (int num : nums) {
            if (num == 1) {
                totalOnes++;
            }
        }

        // If there are no 1's or all are 1's, no swaps needed
        if (totalOnes == 0 || totalOnes == n) {
            return 0;
        }

        // Create an extended array to handle the circular property
        std::vector<int> extendedNums(nums.begin(), nums.end());
        extendedNums.insert(extendedNums.end(), nums.begin(), nums.end());

        // Use a sliding window of size totalOnes
        int minSwaps = totalOnes; // Initialize with the maximum possible swaps
        int currentZeros = 0;
        
        // Count initial zeros in the first window
        for (int i = 0; i < totalOnes; i++) {
            if (extendedNums[i] == 0) {
                currentZeros++;
            }
        }
        minSwaps = std::min(minSwaps, currentZeros);

        // Slide the window over the extended array
        for (int i = totalOnes; i < extendedNums.size(); i++) {
            // Remove the influence of the element going out of the window
            if (extendedNums[i - totalOnes] == 0) {
                currentZeros--;
            }
            // Add the influence of the new element coming into the window
            if (extendedNums[i] == 0) {
                currentZeros++;
            }
            minSwaps = std::min(minSwaps, currentZeros);
        }

        return minSwaps;
    }
};
