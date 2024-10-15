// https://leetcode.com/problems/maximum-length-of-repeated-subarray

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() < nums2.size())
        swap(nums1, nums2);

    const int n2 = nums2.size();
    vector<int> indices2[101];
    for (int i = 0; i < n2; ++i)
        indices2[nums2[i]].emplace_back(i);

    vector<int> dp0(n2 + 1), dp1(n2 + 1);
    vector<int>& prev = dp0;
    vector<int>& curr = dp1;
    int answer = 0, count = sizeof(int) * prev.size();
    for (int num : nums1) {
        memset(prev.data(), 0, count);
        swap(prev, curr);
        for (int i : indices2[num])
            answer = max(answer, curr[i + 1] = prev[i] + 1);
    }
    return answer;
}
};