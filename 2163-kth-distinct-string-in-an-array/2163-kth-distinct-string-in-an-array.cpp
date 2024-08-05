#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequency;
        
        // Count the frequency of each string in the array
        for (const string& str : arr) {
            frequency[str]++;
        }
        
        // Collect distinct strings
        int count = 0;
        for (const string& str : arr) {
            if (frequency[str] == 1) {
                count++;
                if (count == k) {
                    return str;
                }
            }
        }
        
        // If there are fewer than k distinct strings, return an empty string
        return "";
    }
};
