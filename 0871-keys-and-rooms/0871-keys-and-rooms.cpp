#include <vector>
#include <unordered_set>

class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        int n = rooms.size();
        std::unordered_set<int> visited;
        dfs(rooms, visited, 0); // Start DFS from room 0
        return visited.size() == n; // Check if all rooms are visited
    }

private:
    void dfs(std::vector<std::vector<int>>& rooms, std::unordered_set<int>& visited, int room) {
        visited.insert(room); // Mark the current room as visited
        for (int key : rooms[room]) {
            if (visited.find(key) == visited.end()) { // If the key leads to an unvisited room
                dfs(rooms, visited, key); // Recursively visit that room
            }
        }
    }
};