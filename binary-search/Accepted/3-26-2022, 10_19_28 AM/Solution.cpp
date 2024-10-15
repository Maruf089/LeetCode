// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& A, int target) {
        
        if(not binary_search(A.begin(),A.end(),target) )
            return -1;
        
        int pos = lower_bound(A.begin(),A.end(),target) - A.begin();
        return pos;
        
    }
};