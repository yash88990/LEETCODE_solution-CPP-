class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        for (int num : nums) freq[num]++;
        
        for (int num : nums) {
            if (freq[num] > 0 && freq[k - num] > 0) {
                if (num == k - num) {
                    count += freq[num] / 2;
                    freq[num] = 0; 
                } else {
                    count += min(freq[num], freq[k - num]);
                    freq[num] = 0;
                    freq[k - num] = 0;
                }
            }
        }
        
        return count;
    }
};