class Solution {
public:
    int romanToInt(string s) {
        //step 1 :- mapping
        unordered_map<char,int> romanmap = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L', 50},
            {'C', 100},
            {'D' , 500},
            {'M' , 1000}
        };

        int sum = 0;
        int prevval = 0;
        for(int i = s.size() ; i>= 0; i--){
            int val = romanmap[s[i]];
            if(val < prevval){
                sum -= val;
            }else{
                sum += val;
            }
            prevval = val;
        }
        return sum;

    }
};