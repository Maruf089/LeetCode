class Solution {
    public boolean containsDuplicate(int[] nums) {
        boolean res = false;
        Map<Integer,Integer>mp = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(mp.containsKey(nums[i]))
                return true;
            mp.put(nums[i] , 1);
        }
     return res;   
    }
}