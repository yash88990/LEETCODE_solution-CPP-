#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Step 1: Count frequency of each character
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Step 2: Use a max-heap to get characters in descending order
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                pq.push({'a' + i, freq[i]});
            }
        }
        
        string result = "";
        
        while (!pq.empty()) {
            auto [currentChar, count] = pq.top();
            pq.pop();
            
            int useCount = min(count, repeatLimit);
            result.append(useCount, currentChar); // Append the current character
            
            if (count > useCount) {
                // If there are more of the current character left
                if (pq.empty()) break; // If no other character is available, stop
                
                auto [nextChar, nextCount] = pq.top();
                pq.pop();
                
                // Use one of the next largest characters to break the sequence
                result.push_back(nextChar);
                if (nextCount > 1) {
                    pq.push({nextChar, nextCount - 1});
                }
                
                // Push the current character back into the heap with updated count
                pq.push({currentChar, count - useCount});
            }
        }
        
        return result;
    }
};
