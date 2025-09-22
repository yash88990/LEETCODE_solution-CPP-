class Solution {
public:
    int tribonacci(int n) {
        // Base cases
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        // Initialize the first three Tribonacci numbers
        int T0 = 0, T1 = 1, T2 = 1;
        
        // Variable to store the current Tribonacci number
        int Tn;
        
        // Compute the Tribonacci number iteratively
        for (int i = 3; i <= n; ++i) {
            Tn = T0 + T1 + T2; // Compute the next number
            T0 = T1; // Update T0 to T1
            T1 = T2; // Update T1 to T2
            T2 = Tn; // Update T2 to Tn
        }
        
        return Tn;
    }
};