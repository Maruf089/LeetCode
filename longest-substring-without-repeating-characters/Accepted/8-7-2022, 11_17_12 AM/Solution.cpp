// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            
            start = max(start , dict[s[i]] );
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
            
        }
        return maxLen;
    }
};