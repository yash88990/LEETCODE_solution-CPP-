class Solution {
public:
    string predictPartyVictory(string senate) {
        int n= senate.size();
        queue<int>radient , dire;
        for(int i = 0 ; i < n ; i++){
            if(senate[i] == 'R')radient.push(i);
            else dire.push(i);
        }
        while(!radient.empty() && !dire.empty()){
            int rindex = radient.front(); radient.pop();
            int dindex = dire.front(); dire.pop();
            if(rindex < dindex)radient.push(rindex + n);
            else dire.push(dindex + n);
        }
        return radient.empty() ? "Dire" : "Radiant";
    }
};