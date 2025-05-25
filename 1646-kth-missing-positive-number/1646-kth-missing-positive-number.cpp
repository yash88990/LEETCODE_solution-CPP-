class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing = 0;  // count of missing numbers
        int i = 0;        // index for arr
        int current = 1;  // current number to check
        
        while (missing < k) {
            if (i < arr.size() && arr[i] == current) {
                i++; // move to next element in arr
            } else {
                missing++; // current is missing
                if (missing == k) return current;
            }
            current++;
        }
        return -1; // should not reach here
    }
};
