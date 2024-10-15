// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& vc, int k) {
        for(int i = 0 ; i < vc.size() - 1 ; i++){
            int subarraySum = vc[i] ; 
            for(int j = i + 1 ; j < vc.size(); j++){
                subarraySum = (subarraySum + vc[j]);
                // Step 4: Check if the Sum is a Multiple of k
                if (subarraySum == 0 && k == 0) { // Handling special case where k is 0
                    return true;
                }
                if (k != 0 && subarraySum % k == 0) {
                    return true;
                }
            }
        }
        return false; 
    }
};