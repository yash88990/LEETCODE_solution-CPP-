class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxNum; // Maps digit sum to max number seen so far
        int maxSum = -1;
        
        for (int num : nums) {
            int sum = digitSum(num);
            
            if (maxNum.find(sum) != maxNum.end()) {
                maxSum = max(maxSum, maxNum[sum] + num);
            }
            
            maxNum[sum] = max(maxNum[sum], num); // Update max number for this digit sum
        }
        
        return maxSum;
    }
};
