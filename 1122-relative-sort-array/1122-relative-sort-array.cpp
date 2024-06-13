class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> num_cnt;
        for(int num : arr1) num_cnt[num]++;
        int j = 0;
        for(int i : arr2) while (num_cnt[i]-- > 0) arr1[j++] = i;
        for(auto a : num_cnt) while (a.second-- > 0) arr1[j++] = a.first;
        return arr1;
    }
};