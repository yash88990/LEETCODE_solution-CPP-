class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long result = 0;
        int left = 0;
        int max_num = *max_element(nums.begin(), nums.end());
        int count = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == max_num) {
                count++;
            }

            while (count >= k) {
                result += n - right;
                if (nums[left] == max_num) {
                    count--;
                }
                left++;
            }
        }
        
        return result;
    }
};