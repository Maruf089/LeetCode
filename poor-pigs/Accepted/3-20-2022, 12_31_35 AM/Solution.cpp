// https://leetcode.com/problems/poor-pigs

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int round = minutesToTest / minutesToDie ;
        
        int c = 0;
        while( pow((round+1),c)  < buckets )
            c++;
        
        return c;
        
    }
};