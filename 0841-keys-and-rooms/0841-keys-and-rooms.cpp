class Solution {
public:  
    void dfs(vector<vector<int>>& rooms , unordered_set<int>&vis , int room ){
        vis.insert(room);
        for(int key : rooms[room]){
            if(vis.find(key) == vis.end()){
                dfs(rooms , vis , key);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>vis;
        dfs(rooms , vis , 0);
        return rooms.size() == vis.size();
    }
};