class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert the 2x3 board into a string
        string start = "";
        for (const auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }

        string target = "123450"; // Goal state

        // Define neighbors (valid swaps) for each position in the 1D representation
        vector<vector<int>> neighbors = {
            {1, 3},       // neighbors for position 0
            {0, 2, 4},    // neighbors for position 1
            {1, 5},       // neighbors for position 2
            {0, 4},       // neighbors for position 3
            {1, 3, 5},    // neighbors for position 4
            {2, 4}        // neighbors for position 5
        };

        // BFS setup
        queue<pair<string, int>> q; // {current state, number of moves}
        unordered_set<string> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [current, moves] = q.front();
            q.pop();

            // Check if we reached the target
            if (current == target) {
                return moves;
            }

            // Find the position of '0' in the current state
            int zeroPos = current.find('0');

            // Explore all valid moves
            for (int neighbor : neighbors[zeroPos]) {
                string next = current;
                swap(next[zeroPos], next[neighbor]); // Swap '0' with its neighbor

                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, moves + 1});
                }
            }
        }

        // If no solution is found
        return -1;
    }
};
