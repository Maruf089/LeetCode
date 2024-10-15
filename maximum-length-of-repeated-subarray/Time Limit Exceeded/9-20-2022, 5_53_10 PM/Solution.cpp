// https://leetcode.com/problems/maximum-length-of-repeated-subarray

class Solution {
public:
    int findLength(vector<int>& vc1, vector<int>& vc2) {
        
        int ans = 0;
        for(int i = 0 ; i < vc1.size(); i++)
            {
                for(int j = 0; j< vc2.size();j++)
                {
                    if( vc1[i] == vc2[j] )
                    {
                        int cnt = 0, ii = i , jj = j;
                        while(ii < vc1.size() and jj < vc2.size())
                        {
                            if(vc1[ii]==vc2[jj]) cnt++;
                            else break;
                            ii++ , jj++;
                        }
                        ans = max(ans , cnt);
                    }
                }
            }
        return ans;
        
    }
};