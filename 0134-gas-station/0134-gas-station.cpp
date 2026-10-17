class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = 0 , totalcost = 0 , tank = 0 , start =0;
        for(int i = 0 ; i < n ; i++){
            totalcost += cost[i];
            totalgas += gas[i];
        }
        for(int i = 0 ; i< n ; i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                start = i+1 ;
                tank = 0 ;
            }
        }
        return (totalcost > totalgas) ? -1 :start;
    }
};