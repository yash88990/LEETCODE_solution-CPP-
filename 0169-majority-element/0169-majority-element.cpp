class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;

        // Phase 1: Find the majority element (candidate)
        for (int num : nums) {
            if (count == 0) {
                candidate = num;  // Assign a new candidate
                count = 1;
            } else if (num == candidate) {
                count++;  // Increment count if same as candidate
            } else {
                count--;  // Decrement count if different from candidate
            }
        }

        // Phase 2: Return the candidate (since the problem guarantees a majority element)
        return candidate;
    }
};
