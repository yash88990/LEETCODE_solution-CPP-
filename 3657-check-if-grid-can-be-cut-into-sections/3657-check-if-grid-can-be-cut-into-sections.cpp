class Solution {
public:
    bool valid(vector<pair<int, int>>& arr){
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int i = 0;
        vector<pair<int, int>> temp;
        while(i < n){
            int s = arr[i].first;
            int e = arr[i].second;
            i++;
            while(i < n && e > arr[i].first){
                e = max(e, arr[i].second);
                i++;
            }
            temp.push_back({s, e});
        }
        return temp.size()>2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> arr1;
        for(const auto& it : rectangles){
            arr1.push_back({it[0], it[2]});
        }
        if(valid(arr1)) return true;
        vector<pair<int, int>> arr2;
        for(const auto& it : rectangles){
            arr2.push_back({it[1], it[3]});
        }
        if(valid(arr2)) return true;
        return false;
    }
};