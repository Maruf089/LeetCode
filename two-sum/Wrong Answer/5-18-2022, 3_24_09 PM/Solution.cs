// https://leetcode.com/problems/two-sum

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        
        Dictionary<int, int> Map =
        new Dictionary<int, int>();
        
        int len = nums.Length;
        for(int i=0;i<len;i++)
        {
           Map.Add(nums[i] , i+1);
        }
        int a = -1, b = -1 ;
        for(int i=0;i<len;i++)
        {
            int lagbe = target - nums[i];
            if( Map.ContainsKey(lagbe) )
            {
                a = Map[nums[i]] - 1;
                b = Map[lagbe] - 1;
                break;
            }
        }
        
        int [] arr = {a,b};
        return arr;
    }
}