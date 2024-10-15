// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<int>vc[27];
        for(int i=0;i<s.size();i++)
        {
            vc[s[i] - 'a'].push_back(i+1);
        }
        
        int counT = 0 ;
        
        for(auto it : words)
        {
            string ss = it;
            int ase = 1 , prev = -1;
            for(auto i : ss)
            {
                int pos = upper_bound(vc[i - 'a'].begin() , vc[i-'a'].end() , prev )  
                    - vc[i - 'a'].begin();
                if(pos==vc[i - 'a'].size())
                {
                    ase = 0; 
                    break;
                }
                else prev = vc[i-'a'][pos];
            }
            if(ase) counT++;
        }
        
        return counT;
        
    }
};