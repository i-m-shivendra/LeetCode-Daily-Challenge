class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long int ans = INT_MIN;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long int subtract = nums[i] - nums[j];
                    long long int multiply = subtract * nums[k];
                    ans = max(ans, multiply);
                }
            }
        }
        return ans <= 0 ? 0 : ans;
    }
};