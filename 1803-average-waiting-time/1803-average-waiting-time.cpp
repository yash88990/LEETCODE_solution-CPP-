class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long current_time = 0;  // Use long long to avoid overflow
        long long total_waiting_time = 0;

        for (const auto& customer : customers) {
            int arrival = customer[0];
            int time_needed = customer[1];
            
            // Update current_time to the customer's arrival time if it's less
            if (current_time < arrival) {
                current_time = arrival;
            }
            
            // Calculate the waiting time for the current customer
            long long waiting_time = current_time - arrival + time_needed;
            total_waiting_time += waiting_time;
            
            // Update current_time to the time when the chef will be free
            current_time += time_needed;
        }
        
        // Calculate the average waiting time
        return static_cast<double>(total_waiting_time) / n;
    }
};
