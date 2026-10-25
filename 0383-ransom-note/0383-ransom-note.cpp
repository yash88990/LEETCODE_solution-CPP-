class Solution {
public:
    bool canConstruct(string r, string m) {
        int i = 0 , j = 0;
        sort(r.begin() , r.end());
        sort(m.begin() , m.end());
        while(i < r.size() && j < m.size()){
            if(r[i] == m[j]){
                i++;
                j++;
            }else if(r[i] > m[j])j++;
            else return false;
        }
        return i == r.size();
    }
};