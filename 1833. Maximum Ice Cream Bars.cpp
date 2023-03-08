/// Ap 1
class Solution {
public:
    int maxIceCream(vector<int>& vc, int ct) {
        sort(vc.begin(),vc.end());
        int c = 0;
        for(auto it : vc)
        {
            if(ct >= it)
            {
                ct -= it;
                c++;
            }
            else return c;
        }
        return c;
        
    }
};

/// Ap 2 (runtime optimized)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int result = 0;
        int max = *max_element(costs.begin(), costs.end());

        vector<int> countMap(max+1);
        for (auto& cost: costs) {
            countMap[cost]++;
        }

        for (int cost = 1; cost <= max; cost++) {
            if (countMap[cost] == 0) {
                continue;
            }

            if (cost > coins) {
                break;
            }

            int count = min(countMap[cost], coins / cost);
            coins -= count*cost;
            result += count;
        }
        return result;
    }
};