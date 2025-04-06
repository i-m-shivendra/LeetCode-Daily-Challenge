class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size(), maxIdx = -1, maxs = 1;
        if (n == 1) return nums;
        vector<int> store(nums.size(), 1), parent(n, -1);

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (store[i] < store[j] + 1) {
                        store[i] = store[j] + 1;
                        parent[i] = j;
                    }

                    if (maxs < store[i]) {
                        maxs = store[i];
                        maxIdx = i;
                    }
                }
            }
        }
        vector<int> ans;
        if (maxIdx == -1) return {nums[0]};
        
        while (maxIdx != -1) {
            ans.push_back(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }
        return ans;
    }
};