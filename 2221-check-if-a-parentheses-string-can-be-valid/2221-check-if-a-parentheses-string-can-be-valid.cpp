class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        // Agar string ki length odd hai toh valid parentheses nahi ban sakte, kyunki har '(' ke liye ek ')' chahiye
        if (n % 2 != 0) return false;

        // Forward pass: Check karte hain ki '(' ki sufficient quantity ho valid parentheses banane ke liye
        int balance = 0; // Yeh variable track karega ki ab tak kitne '(' zyada hain
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0' || s[i] == '(') {
                // Agar character unlocked hai ya '(' hai, toh usse '(' ki tarah treat karenge
                balance++;
            } else {
                // Agar character ')' hai, toh usse ')' ki tarah treat karenge
                balance--;
            }
            // Agar kabhi ')' zyada ho gaye (balance negative ho gaya), toh yeh string valid nahi ho sakti
            if (balance < 0) return false;
        }

        // Backward pass: Check karte hain ki ')' ki sufficient quantity ho valid parentheses banane ke liye
        balance = 0; // Yeh variable ab track karega ki ab tak kitne ')' zyada hain
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0' || s[i] == ')') {
                // Agar character unlocked hai ya ')' hai, toh usse ')' ki tarah treat karenge
                balance++;
            } else {
                // Agar character '(' hai, toh usse '(' ki tarah treat karenge
                balance--;
            }
            // Agar kabhi '(' zyada ho gaye (balance negative ho gaya), toh yeh string valid nahi ho sakti
            if (balance < 0) return false;
        }

        // Agar dono passes (forward aur backward) successful hain, toh string valid ban sakti hai
        return true;
    }
};
