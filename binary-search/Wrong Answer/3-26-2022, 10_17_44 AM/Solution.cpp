// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& A, int target) {
        
        int pos = lower_bound(A.begin(),A.end(),target) - A.begin();
        if(pos >= A.size()) return -1;
        else return pos;
        
    }
};