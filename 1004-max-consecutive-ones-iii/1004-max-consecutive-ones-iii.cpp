class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int zeroesCount = 0;
        int i = 0;
        int j = 0;

        while(j < n){
            if(nums[j] == 0){
                zeroesCount += 1;
            }

            while(zeroesCount > k){
                if(nums[i] == 0){
                    zeroesCount -= 1;
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};