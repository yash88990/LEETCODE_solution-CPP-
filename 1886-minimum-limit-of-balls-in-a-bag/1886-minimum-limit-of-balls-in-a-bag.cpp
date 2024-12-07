class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isFeasible(nums, mid, maxOperations)) {
                result = mid; // Update result if feasible
                right = mid - 1; // Try for a smaller penalty
            } else {
                left = mid + 1; // Increase penalty to make it feasible
            }
        }
        
        return result;
    }
    
private:
    bool isFeasible(const vector<int>& nums, int penalty, int maxOperations) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > penalty) {
                operations += (balls - 1) / penalty; // Calculate required splits
            }
        }
        return operations <= maxOperations;
    }
};
