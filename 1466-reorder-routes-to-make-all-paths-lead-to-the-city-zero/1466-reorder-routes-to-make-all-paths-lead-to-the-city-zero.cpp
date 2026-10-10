class Solution {
public:
    int cnt = 0;
    void dfs(int node , int parent ,vector<vector<pair<int,int>>>&adj ){
        for(auto &i : adj[node]){
            int neighbor = i.first;
            int sign = i.second;
            if(neighbor != parent){
                cnt += sign;
                dfs(neighbor , node , adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto & edge : connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u,0});
        }
        dfs(0 , -1 , adj);
        return cnt;
    }
};