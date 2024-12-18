// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        int sum = 0 ;
        while(num)
        {
            sum += num % 10;
            num /= 10;
            
            if(num < 10) 
            {
                sum += num % 10;
                if(sum < 10) break;
                num = sum;
                sum = 0;
                
            }
        }
        return sum;
        
    }
};