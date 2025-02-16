class Solution {
public:
    vector<int> result;
    vector<bool> used;
    
    bool backtrack(vector<int>& sequence, int index, int n) {
        // If we have filled the entire sequence, return true
        if (index == sequence.size()) return true;

        // If already filled, move to next index
        if (sequence[index] != 0) return backtrack(sequence, index + 1, n);
        
        // Try placing numbers from n to 1 (lexicographically largest first)
        for (int num = n; num >= 1; --num) {
            if (used[num]) continue;  // Already used
            
            // If num == 1, place it once
            if (num == 1) {
                sequence[index] = 1;
                used[1] = true;
                if (backtrack(sequence, index + 1, n)) return true;
                sequence[index] = 0;
                used[1] = false;
            } else { // Place num in two positions
                int secondIndex = index + num;
                if (secondIndex < sequence.size() && sequence[secondIndex] == 0) {
                    sequence[index] = sequence[secondIndex] = num;
                    used[num] = true;
                    if (backtrack(sequence, index + 1, n)) return true;
                    sequence[index] = sequence[secondIndex] = 0;
                    used[num] = false;
                }
            }
        }
        
        return false; // No valid placement found
    }
    
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> sequence(size, 0);
        used.assign(n + 1, false);
        
        backtrack(sequence, 0, n);
        return sequence;
    }
};
