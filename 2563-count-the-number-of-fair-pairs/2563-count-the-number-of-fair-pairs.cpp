class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int sum = nums[i] + nums[j];
                if(sum >= lower && sum <= upper){
                    ans++;
                }
            }
        }
        return ans;
    }
};