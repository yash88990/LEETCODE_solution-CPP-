class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int regions = 4 * n * n;  // Total number of triangles
        
        // Union-Find data structure
        vector<int> parent(regions);
        iota(parent.begin(), parent.end(), 0);
        
        // Find function with path compression
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        // Union function
        auto unite = [&](int x, int y) {
            parent[find(x)] = find(y);
        };
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int root = 4 * (i * n + j);  // Index of the top-left triangle
                
                // Connect triangles within the cell
                if (grid[i][j] == '/') {
                    unite(root + 0, root + 3); // Connect top-left with bottom-left
                    unite(root + 1, root + 2); // Connect top-right with bottom-right
                } else if (grid[i][j] == '\\') {
                    unite(root + 0, root + 1); // Connect top-left with top-right
                    unite(root + 2, root + 3); // Connect bottom-left with bottom-right
                } else {
                    unite(root + 0, root + 1);
                    unite(root + 1, root + 2);
                    unite(root + 2, root + 3);
                }
                
                // Connect triangles between adjacent cells
                if (i > 0) {
                    unite(root + 0, root - 4 * n + 2); // Connect top-left with bottom-left of the cell above
                }
                if (j > 0) {
                    unite(root + 3, root - 4 + 1); // Connect bottom-left with top-right of the cell to the left
                }
            }
        }
        
        // Count the number of unique roots (regions)
        int count = 0;
        for (int i = 0; i < regions; ++i) {
            if (find(i) == i) count++;
        }
        
        return count;
    }
};
