class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        vector<string> rows(numRows);
        int row = 0;
        int step = 1;

        for (char c : s) {
            rows[row].push_back(c);
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
            row += step;
        }

        string result;
        for (const string& str : rows) {
            result += str;
        }

        return result;
    }
};