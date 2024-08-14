class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Sort the array to enable efficient pairwise distance calculation
        sort(nums.begin(), nums.end());
        
        // Binary search on the distance
        int left = 0;
        int right = nums.back() - nums.front();  // max possible distance
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Count pairs with distance <= mid
            int count = 0;
            int j = 0;
            for (int i = 0; i < nums.size(); ++i) {
                while (j < nums.size() && nums[j] - nums[i] <= mid) {
                    j++;
                }
                count += j - i - 1;
            }
            
            // Adjust the binary search range
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
