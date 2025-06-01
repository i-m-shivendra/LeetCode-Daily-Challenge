class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                ans += 1;
                maxi = max(maxi, ans);
            }
            else{
                ans = 0;
            }
        }
        return maxi;
    }
};