class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string result;
        stringstream ss(path);
        string token;
        
        // Split the path by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Skip empty and current directory tokens
                continue;
            } else if (token == "..") {
                // Move up one directory if possible
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                // Add valid directory or file name to the stack
                stack.push_back(token);
            }
        }
        
        // Reconstruct the canonical path from the stack
        for (const string& dir : stack) {
            result += "/" + dir;
        }
        
        // Return "/" if result is empty, otherwise return the result
        return result.empty() ? "/" : result;
    }
};
