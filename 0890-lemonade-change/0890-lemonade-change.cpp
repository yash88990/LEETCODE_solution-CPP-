class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;  // Variables to keep track of $5 and $10 bills
        
        for (int bill : bills) {
            if (bill == 5) {
                five++;  // Received a $5 bill, no change needed
            } 
            else if (bill == 10) {
                if (five > 0) {
                    five--;  // Give back a $5 bill as change
                    ten++;   // Keep the $10 bill
                } else {
                    return false;  // Can't provide change
                }
            } 
            else {  // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;  // Give back a $10 bill
                    five--; // Give back a $5 bill
                } 
                else if (five >= 3) {
                    five -= 3;  // Give back three $5 bills
                } 
                else {
                    return false;  // Can't provide change
                }
            }
        }
        
        return true;  // Successfully provided change for all customers
    }
};
