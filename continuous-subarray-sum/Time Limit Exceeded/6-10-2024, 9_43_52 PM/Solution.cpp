// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& vc, int k) {
        long long arr[100000+9] = {0};
        for(int i = 0 ; i < vc.size() ; i++){
            arr[i + 1] = arr[i] + vc[i];
        }
        for(int i = 0 ; i < vc.size() ; i++){
            arr[i + 1] = arr[i] + vc[i];
        }
        bool f = false;
        for(int i = 0 ; i < vc.size() ; i++){
            long long sum = 0 ; 
            for(int j = i ; j < vc.size(); j++){
                sum = (arr[j+1] - arr[i]);
                if((j - i + 1) >= 2 and sum % k == 0) 
                {
                    f = true;
                    break;
                }
            }
        }
        return f; 
    }
};