// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& vc, int k) {
        long long arr[100000+9] = {0};
        for(int i = 0 ; i < vc.size() ; i++){
            arr[i + 1] = arr[i] + vc[i];
        }
        
        bool f = false;
        for(int i = 0 ; i < vc.size() ; i++){
            long long subarraySum = 0 ; 
            for(int j = i + 1 ; j < vc.size(); j++){
                subarraySum = (arr[j+1] - arr[i]);
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