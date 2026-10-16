class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin() , c.end() , greater<int>());
        int index = 0;
        for(int i = 0 ;i < c.size() ; i++){
            if(c[i] >= i+1)index = i+1;
            else break;
        }
        return index;
    }
};