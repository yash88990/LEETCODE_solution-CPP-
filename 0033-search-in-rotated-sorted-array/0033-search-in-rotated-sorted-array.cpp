class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if we found the target
            if (nums[mid] == target) {
                return mid;
            }
            
            // Determine which side is properly sorted
            if (nums[left] <= nums[mid]) {
                // Left side is sorted
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;  // Search in the left part
                } else {
                    left = mid + 1;   // Search in the right part
                }
            } else {
                // Right side is sorted
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;   // Search in the right part
                } else {
                    right = mid - 1;  // Search in the left part
                }
            }
        }
        
        return -1;  // Target not found
    }
};
