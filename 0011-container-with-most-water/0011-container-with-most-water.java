class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxarea = Integer.MIN_VALUE; // Mirrored from C++ INT_MIN

        while (left < right) {
            int w = right - left;
            int h = Math.min(height[left], height[right]);
            int area = w * h;
            
            maxarea = Math.max(maxarea, area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxarea;
    }
}