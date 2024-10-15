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
                num = sum;
                sum = 0;
                
                if(num < 10) break;
            }
        }
        return sum;
        
    }
};