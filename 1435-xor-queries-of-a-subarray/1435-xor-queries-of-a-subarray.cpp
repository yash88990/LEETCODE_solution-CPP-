class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXOR(n);  // To store prefix XOR values
        vector<int> result;        // To store the final results
        
        // Step 1: Compute prefix XOR array
        prefixXOR[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
        }
        
        // Step 2: Answer each query using the prefix XOR array
        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            if (left == 0) {
                // If left is 0, then the XOR is just the prefixXOR[right]
                result.push_back(prefixXOR[right]);
            } else {
                // Otherwise, XOR between prefixXOR[right] and prefixXOR[left-1]
                result.push_back(prefixXOR[right] ^ prefixXOR[left - 1]);
            }
        }
        
        return result;
    }
};
