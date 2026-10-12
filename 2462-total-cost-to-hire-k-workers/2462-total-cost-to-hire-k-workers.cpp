class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> left , right;
        long long totalcost = 0;
        int n = costs.size();
        int leftindex = candidates;
        int rightindex = n - candidates - 1;
        for(int i = 0 ; i < candidates  && i < n ; i++)left.push(costs[i]);
        for(int i = max(candidates , n - candidates) ; i < n ; i++)right.push(costs[i]);
        for(int i = 0 ;i < k ; i++){
            int ltop = left.empty() ? INT_MAX: left.top();
            int rtop = right.empty() ? INT_MAX : right.top();
            if(ltop <= rtop){
                totalcost += ltop;
                left.pop();
                if(leftindex <= rightindex)left.push(costs[leftindex++]);
            }else{
                totalcost += rtop;
                right.pop();
                if(leftindex <= rightindex)right.push(costs[rightindex--]);
            }
        }
        
        return totalcost;
    }
};