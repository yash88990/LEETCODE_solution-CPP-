class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool>visited(n , false);
        //create adj list
        for(auto & edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
        }
        int result = 0;
        for(int i =0 ;i < n ; i++){
            if(!visited[i]){
                vector<int> componentNodes;
                queue<int>q;
                q.push(i);
                visited[i] = true;
                //bfs 
                while(!q.empty()){
                    int node = q.front() ; q.pop();
                    componentNodes.push_back(node);
                    for(int neighbour : adj[node]){
                        if(!visited[neighbour]){
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }

                }
                int k = componentNodes.size();
                int edgeCount = 0;
                //count edge inside the components
                for(int node : componentNodes){
                    edgeCount += adj[node].size();
                }
                edgeCount /= 2;
                //check for complete 
                if(edgeCount == k * ( k-1) / 2)result++;

            }
        }
        return result;
        
    }
};