import java.util.Stack;

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> asteroidStack = new Stack<>();

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                // Moving to the right, always push to stack
                asteroidStack.push(asteroid);
            } else {
                // Moving to the left, check for collisions
                while (!asteroidStack.isEmpty() && asteroidStack.peek() > 0 && asteroidStack.peek() < Math.abs(asteroid)) {
                    asteroidStack.pop();
                }

                if (asteroidStack.isEmpty() || asteroidStack.peek() < 0) {
                    asteroidStack.push(asteroid);
                } else if (asteroidStack.peek() == Math.abs(asteroid)) {
                    asteroidStack.pop();
                }
            }
        }

        // Convert stack back to array
        int[] result = new int[asteroidStack.size()];
        for (int i = asteroidStack.size() - 1; i >= 0; i--) {
            result[i] = asteroidStack.pop();
        }

        return result;
    }
}