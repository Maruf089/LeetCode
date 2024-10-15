// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {

        int ret = 0;
        for(int i = 0 ; i< word.size(); i++ )
        {
            if( word[i]>='A' and word[i] <= 'Z')
               ret++;
        }
      //  cout << ret;
        if(ret==0 or ret==1 or ret==word.size())
            return true;
        else return false;
        
    }
};