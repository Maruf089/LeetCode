class Solution {
public:
    bool detectCapitalUse(string word) {

        int small = 0, big = 0;
        for(int i = 0 ; i< word.size(); i++ )
        {
            if( word[i]>='A' and word[i] <= 'Z')
               big++;
            else small++;
        }
        
        if(small==word.size() or big==word.size())
            return true;
        else if(big==1 and word[0]>='A' and word[0]<='Z')
            return true;
        else return false;
        
    }
};