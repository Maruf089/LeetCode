class Solution {
    public void sortColors(int[] nums) {
        int lo = 0 , mid = 0 , hi = nums.length - 1;
        while(mid <= hi){ // remember mid <= hi
            
            if(nums[mid]==0){
                int tmp = nums[lo];
                nums[lo] = nums[mid];
                nums[mid] = tmp;
                lo++; mid++;  // remember both ++
            }
            else if(nums[mid]==2){
                int tmp = nums[hi];
                nums[hi] = nums[mid];
                nums[mid] = tmp;
                hi--;  // remember only hi ++
            }
            else mid++;
        }
        
    }
}