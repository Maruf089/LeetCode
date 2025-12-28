class Solution {
    public int singleNonDuplicate(int[] nums) {
        int low = 0 , high = nums.length - 1;
        while(low < high){
            int mid = (low + high) / 2;
            int next_val = (mid%2==0) ? mid + 1 : mid-1;
            if(nums[mid]==nums[next_val])
                low = mid + 1;
            else high = mid;
        }
        return nums[high];
        
    }
}