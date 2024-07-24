#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function to map a number according to the mapping array
    string getMappedValue(int num, const vector<int>& mapping) {
        string numStr = to_string(num);
        string mappedStr;
        for (char digit : numStr) {
            mappedStr += to_string(mapping[digit - '0']);
        }
        return mappedStr;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Create a vector of pairs to store the original numbers and their mapped values as strings
        vector<pair<string, int>> mappedNums;
        for (int num : nums) {
            mappedNums.push_back({getMappedValue(num, mapping), num});
        }

        // Sort the pairs based on the mapped values as strings
        stable_sort(mappedNums.begin(), mappedNums.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return stoll(a.first) < stoll(b.first);
        });

        // Extract the sorted numbers based on the original numbers' order
        vector<int> sortedNums;
        for (const auto& pair : mappedNums) {
            sortedNums.push_back(pair.second);
        }

        return sortedNums;
    }
};
