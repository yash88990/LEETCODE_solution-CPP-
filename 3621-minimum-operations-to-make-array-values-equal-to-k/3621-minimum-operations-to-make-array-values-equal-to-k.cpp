class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Check for impossible case
        for (int num : nums) {
            if (num < k) return -1;
        }

        // Store all distinct values greater than k
        unordered_set<int> greaterThanK;
        for (int num : nums) {
            if (num > k) {
                greaterThanK.insert(num);
            }
        }

        // Each distinct value > k will require one operation
        return greaterThanK.size();
    }
};
