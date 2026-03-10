class Solution {
    public int[] searchRange(int[] nums, int target) {
        int s = 0, e = nums.length - 1;
        int first = -1, last = -1;

        // first occurrence
        while(s <= e){
            int m = s + (e - s) / 2;

            if(nums[m] == target){
                first = m;
                e = m - 1;
            } else if(nums[m] < target){
                s = m + 1;
            } else {
                e = m - 1;
            }
        }

        s = 0;
        e = nums.length - 1;

        // last occurrence
        while(s <= e){
            int m = s + (e - s) / 2;

            if(nums[m] == target){
                last = m;
                s = m + 1;
            } else if(nums[m] < target){
                s = m + 1;
            } else {
                e = m - 1;
            }
        }

        return new int[]{first, last};
    }
}