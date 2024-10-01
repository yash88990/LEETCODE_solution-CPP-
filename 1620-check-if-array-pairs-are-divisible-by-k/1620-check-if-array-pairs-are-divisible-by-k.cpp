class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // Create a frequency array for remainders
        vector<int> remainderFreq(k, 0);
        
        // Calculate the remainders and count them
        for (int num : arr) {
            int remainder = ((num % k) + k) % k; // Ensure non-negative remainder
            remainderFreq[remainder]++;
        }
        
        // Check for remainder pairs
        for (int i = 1; i < k; i++) {
            // Check if remainder i and remainder (k - i) have the same frequency
            if (remainderFreq[i] != remainderFreq[k - i]) {
                return false;
            }
        }
        
        // Check the count of elements that are perfectly divisible by k (remainder 0)
        return remainderFreq[0] % 2 == 0;
    }
};
