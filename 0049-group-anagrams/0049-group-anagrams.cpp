class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> map;
        for(string s : strs){
            string sorted_str = s;
            sort(sorted_str.begin() , sorted_str.end());
            map[sorted_str].push_back(s);
        }
        vector<vector<string>> result;
        for(auto i : map){
            result.push_back(i.second);
        }
        return result;


    }
};