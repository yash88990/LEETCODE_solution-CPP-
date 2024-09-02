class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Step 1: Calculate the total chalk required for one complete round
        long long total_chalk = 0;
        for (int c : chalk) {
            total_chalk += c;
        }
        
        // Step 2: Reduce k by the total chalk modulo
        k = k % total_chalk;
        
        // Step 3: Find the student who will replace the chalk
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        // This point should never be reached because we are guaranteed to find a student
        return -1;
    }
};
