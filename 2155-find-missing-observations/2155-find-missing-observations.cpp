class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        
        // Step 1: Calculate totalSum
        int totalSum = mean * (n + m);
        
        // Step 2: Calculate sum of known rolls
        int sumOfRolls = 0;
        for (int roll : rolls) {
            sumOfRolls += roll;
        }
        
        // Step 3: Calculate missingSum
        int missingSum = totalSum - sumOfRolls;
        
        // Step 4: Check feasibility
        if (missingSum < n || missingSum > 6 * n) {
            // It's impossible to distribute missingSum across n rolls with each roll between 1 and 6
            return {};
        }
        
        // Step 5: Distribute missingSum across n rolls
        vector<int> result(n, 1);  // Start by assuming all missing rolls are 1
        missingSum -= n;  // Adjust missingSum after initializing each roll to 1
        
        for (int i = 0; i < n && missingSum > 0; ++i) {
            int add = min(5, missingSum);  // We can add at most 5 to make the roll at most 6
            result[i] += add;
            missingSum -= add;
        }
        
        return result;
    }
};
