class Solution {
public:
    void solve(string digits,vector<string>&ans, string output,int index, string mapping[]){
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }
        int number = digits[index]  - '0';
        string values = mapping[number];
        for(int i = 0 ; i < values.size() ; i++){
            output.push_back(values[i]);
            solve(digits , ans , output , index + 1 , mapping);
            //backtrack
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size() == 0)return ans;
        string output ="";
        int index = 0 ;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits , ans , output , index , mapping);
        return ans;
    }
};