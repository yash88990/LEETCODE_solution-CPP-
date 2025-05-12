class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> freq;
        for (int d : digits) freq[d]++;
        
        set<int> result; // to automatically store unique & sorted numbers
        
        // Try all 3-digit numbers
        for (int i = 100; i <= 999; ++i) {
            if (i % 2 != 0) continue; // must be even
            
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            unordered_map<int, int> tempFreq;
            tempFreq[a]++;
            tempFreq[b]++;
            tempFreq[c]++;

            bool valid = true;
            for (auto& [digit, count] : tempFreq) {
                if (freq[digit] < count) {
                    valid = false;
                    break;
                }
            }

            if (valid) result.insert(i);
        }

        return vector<int>(result.begin(), result.end());
    }
};
