class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generate("", n, n, result);
        return result;
    }
    
    void generate(std::string current, int open, int close, std::vector<std::string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        
        if (open > 0) {
            generate(current + '(', open - 1, close, result);
        }
        
        if (close > open) {
            generate(current + ')', open, close - 1, result);
        }
    }
};