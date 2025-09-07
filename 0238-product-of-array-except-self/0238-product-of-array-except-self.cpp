#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Step 1: Build prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;   // store product of elements before i
            prefix *= nums[i];    // update prefix
        }

        // Step 2: Multiply with suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;  // multiply by product of elements after i
            suffix *= nums[i];    // update suffix
        }

        return answer;
    }
};
