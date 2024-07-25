#include <vector>
#include <cstdlib>

class Solution {
public:
    void quicksort(std::vector<int>& nums, int left, int right) {
        if (left < right) {
            int pivotIndex = partition(nums, left, right);
            quicksort(nums, left, pivotIndex - 1);
            quicksort(nums, pivotIndex + 1, right);
        }
    }
    
    int partition(std::vector<int>& nums, int left, int right) {
        int pivotIndex = left + rand() % (right - left + 1); // Random pivot
        int pivotValue = nums[pivotIndex];
        std::swap(nums[pivotIndex], nums[right]); // Move pivot to end
        int storeIndex = left;
        
        for (int i = left; i < right; ++i) {
            if (nums[i] < pivotValue) {
                std::swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }
        std::swap(nums[storeIndex], nums[right]); // Move pivot to its final place
        return storeIndex;
    }
    
    std::vector<int> sortArray(std::vector<int>& nums) {
        srand(time(0)); // Seed for random number generator
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};
