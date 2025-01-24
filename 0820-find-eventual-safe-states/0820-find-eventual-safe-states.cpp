class Solution {
public:
bool dfs(int u , vector<vector<int>>& graph ,vector<bool> &safe , vector<int> &state){
    if(state[u] != -1) return state[u];
    state[u] = 0 ; // unsafe
    for(int v : graph[u]){
        if(!dfs(v , graph  , safe , state))
           return state[u] = 0 ;
    }
    state[u] = 1 ; //safe
    safe[u] = true;
    return true;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n  = graph.size();
        vector<bool> safe(n , false);
        vector<int> state(n , -1);
        vector<int> result;
        for(int i = 0 ; i < n ; i++){
            if(state[i] == -1){
                dfs(i , graph, safe , state);
            }
        }
        for(int i = 0 ; i  < n ; i++){
            if(safe[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};