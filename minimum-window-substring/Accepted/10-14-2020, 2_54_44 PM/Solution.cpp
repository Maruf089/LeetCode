// https://leetcode.com/problems/minimum-window-substring

class Solution
{
public:
    string minWindow(string s,string t)
    {
        int s_len = s.size();
        int t_len = t.size();

        vector<int>freq_t(256,0);
        vector<int>freq_s(256,0);
        for(int i=0;i<t_len;i++)
            freq_t[t[i]]++;

        int win_left = 0 , ans = INT_MAX , ans_left,counT = 0 ;
         for(int i=0;i<s_len;i++)
         {
             if(freq_t[s[i]]>0 and freq_t[s[i]]>freq_s[s[i]])
                counT++;
             freq_s[s[i]]++;
             if(counT==t_len)
             {
                 /*
				All characters required are in current window
                Now , try to minimize window by removing extra character at the start of window
                */

                 while(win_left<i and (freq_t[s[win_left]]<freq_s[s[win_left]] or freq_t[s[win_left]]==0))
                 {
                     /// remove Extra frequency or zero frequency characters
                     if(freq_t[s[win_left]]<freq_s[s[win_left]])
                        freq_s[s[win_left]]--;
                     win_left++;
                 }
                 if(ans>(i-win_left+1))
                 {
                     ans = i-win_left+1;
                     ans_left = win_left;
                 }
             }
         }
         if(ans==INT_MAX)
            return "";
         else return s.substr(ans_left,ans);
    }
};
