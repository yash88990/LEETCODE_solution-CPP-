class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k > n
        
        // Solution 1: Reverse Technique
        reverse(nums.begin(), nums.end()); // Reverse the entire array
        reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
        reverse(nums.begin() + k, nums.end()); // Reverse the remaining elements
        
        // Solution 2: Using Additional Array
        /*
        vector<int> rotated(n);
        for (int i = 0; i < n; ++i) {
            rotated[(i + k) % n] = nums[i];
        }
        nums = rotated;
        */
        
        // Solution 3: Using Cyclic Replacements
        /*
        int count = 0;
        for (int start = 0; count < n; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                ++count;
            } while (start != current);
        }
        */
    }
};
