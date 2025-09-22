/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // This helps prevent overflow compared to (low + high) / 2
            int result = guess(mid);
            
            if (result == 0) {
                return mid; // The correct number is found
            } else if (result == -1) {
                high = mid - 1; // The target number is lower than mid
            } else {
                low = mid + 1; // The target number is higher than mid
            }
        }
        
        // If we exit the loop without returning, it means the number wasn't found (shouldn't happen with valid inputs)
        return -1; 
    }
};