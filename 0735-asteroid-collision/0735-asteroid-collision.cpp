class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int a : asteroids ){
            //if +ve :- right direction
            if(a > 0){
                s.push(a);

            }else{ // -ve :- left direction
                // when satck is non empty && stack have lesser value then remove it  
                while(!s.empty() && s.top() > 0 && s.top() < abs(a)){
                    s.pop();
                }
                // if  stack is empty or s have -ve value 
                if(s.empty() || s.top() < 0)s.push(a);
                // both have same value with opp direction :- both will be distroy
                else if(s.top() == abs(a))s.pop();

            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();

        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};