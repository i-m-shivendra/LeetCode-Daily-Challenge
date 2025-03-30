class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        int result = INT_MAX;
        for(int i=0;i<n;i++){
            result = min(result, cost[i]);
            cost[i] = result;
        }
        return cost;
    }
};