class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long current_time = 0;
        long long total_waiting_time = 0 ;
        for(const auto& customer : customers){
            int arrival = customer[0];
            int time_needed = customer[1];
            if(current_time < arrival ){
                current_time = arrival ;
            }
            long long waiting_time  = current_time + time_needed - arrival ;
            total_waiting_time += waiting_time ;
            current_time += time_needed ; 
        } 
        return static_cast<double>(total_waiting_time) / n ;
    }
};