class Solution {
public:
    // Helper function to find the root (with path compression)
    int find(int x, unordered_map<int, int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent); // Path compression
        }
        return parent[x];
    }
    
    // Helper function to union two components
    void unite(int x, int y, unordered_map<int, int>& parent) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if (rootX != rootY) {
            parent[rootX] = rootY; // Union the two components
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent;
        
        // Initialize each stone's position as its own parent
        for (const auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 100000; // Offset column by a large number to avoid overlap
            if (parent.find(row) == parent.end()) {
                parent[row] = row;
            }
            if (parent.find(col) == parent.end()) {
                parent[col] = col;
            }
            unite(row, col, parent); // Union row and column
        }
        
        // Count the number of distinct connected components
        unordered_set<int> uniqueComponents;
        for (const auto& stone : stones) {
            int row = stone[0];
            uniqueComponents.insert(find(row, parent)); // Find the root component of each row
        }
        
        // The maximum number of stones that can be removed is the total number of stones
        // minus the number of connected components
        return stones.size() - uniqueComponents.size();
    }
};
