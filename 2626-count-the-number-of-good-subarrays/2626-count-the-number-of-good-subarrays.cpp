class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long res = 0;
        long long pairCount = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            // Add current element to freq map
            pairCount += freq[nums[right]];
            freq[nums[right]]++;

            // Shrink the window until we have enough pairs
            while (pairCount >= k) {
                res += n - right; // all subarrays starting from left to right-end
                pairCount -= freq[nums[left]] - 1;
                freq[nums[left]]--;
                left++;
            }
        }

        return res;
    }
};
