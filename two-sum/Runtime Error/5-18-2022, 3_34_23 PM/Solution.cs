// https://leetcode.com/problems/two-sum

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        
        Dictionary<int, int> Map =
        new Dictionary<int, int>();
        
        int len = nums.Length;
       
        int a = -1, b = -1 ;
        for(int i=0;i<len;i++)
        {
            int lagbe = target - nums[i];
            if( Map.ContainsKey(lagbe))
            {
                a = i;
                b = Map[lagbe] ;
                break;
            }
            
            Map.Add(nums[i] , i);
        }
        
     //   Console.WriteLine(a + " " + b);
        
        int [] arr = {a,b};
        return arr;
    }
}