// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one= 0 , two = 0 , zero = 0 ;
        for(auto it : nums)
        {
            if(it==0)
            zero++;
            else if(it==1)
                one++;
            else two++;
        }
        for(int i= 0 ; i<nums.size();i++)
        {
            if(zero)
            {cout << 0;
            zero--;}
            else if(one)
            {cout << 1;
            one--;}
            else
            {
                cout << 2 ;
                two--;
            }
            if(i<nums.size()-1)
                cout << ' ';
        }
        cout << endl;
    }
};