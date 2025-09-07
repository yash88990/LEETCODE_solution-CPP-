#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        
        for (int num : nums) {
            if (num <= first) {
                first = num;  // new smallest
            } else if (num <= second) {
                second = num; // num is bigger than first but smaller than second
            } else {
                // num > first and num > second → triplet exists
                return true;
            }
        }
        return false;
    }
};
