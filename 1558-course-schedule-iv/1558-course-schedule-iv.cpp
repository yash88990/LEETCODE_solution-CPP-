class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(numCourses , vector<bool>(numCourses , false));
        for(auto & pre: prerequisites){
            reachable[pre[0]][pre[1]] = true;

        }
        for(int i = 0 ; i < numCourses ; i++){
            for(int j = 0 ; j < numCourses; j++){
                for(int k = 0 ; k < numCourses ; k++){
                    if(reachable[k][i] && reachable[i][j]){
                        reachable[k][j] = true;
                    }
                }
            }
        }
        vector<bool> answer;
        for(auto& query : queries){
            answer.push_back(reachable[query[0]][query[1]]);
        }
        return answer;

        
    }
};