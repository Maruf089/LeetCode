// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {

        if(word[0]>='a' and word[0]<='z') return false;
        int ret = 0;
        for(int i = 0 ; i< word.size(); i++ )
        {
            if( word[i]>='A' and word[i] <= 'Z')
               ret++;
        }
        return (ret==1 or ret==word.size());
        
    }
};