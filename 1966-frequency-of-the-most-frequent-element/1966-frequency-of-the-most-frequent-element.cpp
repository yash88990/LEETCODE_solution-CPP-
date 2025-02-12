
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        long long left = 0, total = 0, maxFreq = 1;
        for (long long right = 0; right < nums.size(); right++) {
            total += nums[right];
            while ((right - left + 1) * nums[right] - total > k) {
                total -= nums[left]; 
                left++; 
            }
            maxFreq = max(maxFreq, right - left + 1);
        }
        return maxFreq;
    }
};
