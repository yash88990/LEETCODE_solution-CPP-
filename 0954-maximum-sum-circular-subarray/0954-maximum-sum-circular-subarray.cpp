#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Step 1: Array ka size n find karo
        int n = nums.size();

        // Step 2: Total sum calculate karne ke liye ek variable banayein
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num; // Array ke sabhi elements ka sum
        }

        // Step 3: Maximum subarray sum without wrapping find karte hain (Kadane's Algorithm use karke)
        int maxSum = INT_MIN, currentMax = 0;
        for (int num : nums) {
            currentMax = max(num, currentMax + num); // Maximum subarray ka sum track karo
            maxSum = max(maxSum, currentMax); // Overall maximum update karo
        }

        // Step 4: Minimum subarray sum without wrapping find karte hain
        int minSum = INT_MAX, currentMin = 0;
        for (int num : nums) {
            currentMin = min(num, currentMin + num); // Minimum subarray ka sum track karo
            minSum = min(minSum, currentMin); // Overall minimum update karo
        }

        // Step 5: Check agar saare numbers negative hain
        if (maxSum < 0) {
            return maxSum; // Agar saare negative hain to maximum single element hi hoga
        }

        // Step 6: Circular subarray ka maximum sum find karo
        int circularMaxSum = totalSum - minSum; // Total sum se minimum subarray ko minus karke circular sum nikaalo

        // Step 7: Return the maximum of normal max sum aur circular max sum
        return max(maxSum, circularMaxSum);
    }
};
