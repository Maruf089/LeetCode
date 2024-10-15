// https://leetcode.com/problems/minimum-operations-to-halve-array-sum

class Solution {
public:
    int halveArray(vector<int>& nums) {

        int counT = 0 ;
        double sum = 0 ;
        priority_queue<double>Q;

        for(auto it : nums)
        {
            double d = it*1.00;
            sum += d;
            Q.push(d);
        }

        double half = (sum * 1.00)  / 2.00 ;

      //  dbg(sum , half, Q.size());

        while(1)
        {
         //   dbg(sum , half);

            if(sum <= half ) break;

            counT++;
            auto it = Q.top();
            Q.pop();
            double d = ( ( (double)(it)*1.00 ) / 2.00 ) ;
            sum -=  d ;
            Q.push(d);

         //   cout << it << ' ' << d << ' ' << counT << endl;

        }

        return counT;

}
};