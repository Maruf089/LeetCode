// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        vector<char>vc[2000];
        int n;
        for(auto it : strs)
        {
            int idx = 0 ;
            for(auto ch : it)
            {
                vc[idx].push_back(ch);
                idx++;
            }
            n = it.size();
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            string prev = "" , next = "";
            for(auto it : vc[i])
                prev += it;
            sort(vc[i].begin(),vc[i].end());
            for(auto it : vc[i])
                next += it;

            if( prev != next )
                ans++;

        }

        return ans;


        
    }
};