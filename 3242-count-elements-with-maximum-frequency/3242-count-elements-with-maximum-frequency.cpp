class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }
        
        // Find the maximum frequency
        int maxFreq = 0;
        for (auto& [key, value] : freq) {
            maxFreq = max(maxFreq, value);
        }
        
        // Sum the frequencies of elements that have the maximum frequency
        int sum = 0;
        for (auto& [key, value] : freq) {
            if (value == maxFreq) {
                sum += value;
            }
        }
        
        return sum;
    }
};
