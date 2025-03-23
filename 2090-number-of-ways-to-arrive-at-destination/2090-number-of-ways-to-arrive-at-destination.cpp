class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Step 1: Build graph
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].emplace_back(v, time);
            adj[v].emplace_back(u, time);
        }

        // Step 2: Initialize distance and ways
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0); // {distance, node}

        // Step 3: Dijkstra's algorithm
        while (!pq.empty()) {
            auto [currDist, node] = pq.top(); pq.pop();

            if (currDist > dist[node]) continue;

            for (auto& [neighbor, time] : adj[node]) {
                long long newDist = currDist + time;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.emplace(newDist, neighbor);
                } else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
