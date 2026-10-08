class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>ans;

        for(int a : asteroids){
            //pos 
            if(a > 0)ans.push(a);
            //neg
            else{
                //top is pos 
                while(!ans.empty() && ans.top() > 0 && ans.top() < abs(a))ans.pop();
                //top is neg
                if(ans.empty()  || ans.top() < 0)ans.push(a);
                else if(ans.top() == abs(a))ans.pop();
            }

        }
        vector<int>res;
        while(!ans.empty()){
            res.push_back(ans.top());
            ans.pop();
        }
        reverse(res.begin() , res.end());
        return res;
    }
};