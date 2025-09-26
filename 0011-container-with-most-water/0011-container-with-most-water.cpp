class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0 , right = height.size()-1 , maxi = INT_MIN;
        while(left < right){
            int w = right - left;
            int h =  min(height[left] , height[right]);
            int area = w * h;
            maxi = max(area , maxi);
            if(height[left] < height[right])left++;
            else right--;


        }
        return maxi;
    }
};