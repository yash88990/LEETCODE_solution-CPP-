class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        
        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }
        
        // Check for pairs that sum up to k
        for (int num : nums) {
            if (freq[num] > 0 && freq[k - num] > 0) {
                if (num == k - num) {
                    // If both numbers are the same, check if there are enough occurrences to form a pair
                    count += freq[num] / 2;
                    freq[num] = 0; // Remove the occurrences
                } else {
                    // Otherwise, take the minimum occurrences between num and k - num
                    count += min(freq[num], freq[k - num]);
                    freq[num] = 0;
                    freq[k - num] = 0;
                }
            }
        }
        
        return count;
    }
};
