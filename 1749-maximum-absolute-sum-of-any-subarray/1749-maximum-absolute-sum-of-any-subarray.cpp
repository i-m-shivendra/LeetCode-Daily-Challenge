class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int minSum = 0;
        int maxSum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];

            if(sum >maxSum){
                maxSum = sum;
            }
    
            if(sum < minSum){
                minSum = sum;
            }
        }
        return abs(maxSum - minSum);
    }
};