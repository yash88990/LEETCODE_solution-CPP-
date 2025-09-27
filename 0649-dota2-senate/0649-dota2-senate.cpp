class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r , d;
        int n = senate.size();
        for(int i = 0 ; i < senate.size() ; i++){
            if(senate[i] == 'R')r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()){
            int rindex = r.front();
            int dindex = d.front();
            r.pop();
            d.pop();
            if(rindex < dindex)r.push(rindex + n);
            else d.push(dindex + n);
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};