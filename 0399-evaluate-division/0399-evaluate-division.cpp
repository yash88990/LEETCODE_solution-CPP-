class Solution {
public:
    double dfs(string curr , string target , unordered_map<string , unordered_map<string , double>> graph , unordered_set<string>vis ){
        if(curr == target)return 1.0;
        vis.insert(curr);
        for(auto &i : graph[curr] ){
            string nextnode = i.first;
            double weight = i.second;
            if(vis.find(nextnode) == vis.end()){
                double ans = dfs(nextnode , target , graph , vis);
                if(ans != -1)return weight * ans;
            }
        }
        return -1.0;

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //step 1 :- build the graph
        unordered_map<string , unordered_map<string , double>> graph;
        for(int i = 0 ; i < equations.size() ; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            graph[u][v] = val;
            graph[v][u] =  1.0 / val;
        }
        //step 2 :- call dfs - process each queries
        vector<double> result;
        for(auto &query : queries){
            string start = query[0];
            string end = query[1];
            if(graph.find(start) == graph.end() || graph.find(end) == graph.end())result.push_back(-1.0);
            else if(start == end)result.push_back(1.0);
            else{
                unordered_set<string>vis;
                double res = dfs(start , end , graph , vis);
                result.push_back(res);
            }
        }
        return result;
    }
};