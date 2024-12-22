class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = {0,1};
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<nums.length;j++){
                if(i!=j){
                    if(nums[i] + nums[j] == target){
                        res[0] = i; res[1] = j;
                    }
                }
            }
        }
        return res;
    }
}