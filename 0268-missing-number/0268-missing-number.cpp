class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actualsum = 0;
        int n = nums.size();
        int expectedsum = n * ( n + 1 ) / 2;
        for(int num : nums){
            actualsum += num;
        }
        return expectedsum - actualsum;

    }
};