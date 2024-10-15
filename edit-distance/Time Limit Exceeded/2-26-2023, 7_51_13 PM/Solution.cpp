// https://leetcode.com/problems/edit-distance

class Solution {
public:

    int solve(int pos1,int pos2,string word1,string word2)
    {
        if(pos1 < 0)
            return pos2 + 1;
        if(pos2 < 0)
            return pos1 + 1;
        if(word1[pos1] != word2[pos2] )
        {
            return min( {solve(pos1-1,pos2-1,word1,word2),
                        solve(pos1,pos2-1,word1,word2),
                        solve(pos1-1,pos2,word1,word2) } ) + 1;
        }
        else
        {
           return solve(pos1-1,pos2-1,word1,word2);
        }

    }
    int minDistance(string word1, string word2) {
        return solve(word1.size()-1,word2.size()-1,word1,word2);
    }
};