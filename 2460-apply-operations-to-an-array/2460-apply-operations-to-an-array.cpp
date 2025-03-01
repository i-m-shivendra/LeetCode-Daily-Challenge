class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }

        int start = 0;
        int end = n-1;

        while(start <= end){
            if(nums[start] == 0 && nums[end] > 0){
                swap(nums[start++],nums[end--]);
            }

            else if(nums[start] == 0 && nums[end] == 0){
                end--;
            }

            else if(nums[start] > 0 && nums[end] > 0){
                start++;
            }

            else if(nums[start] > 0 && nums[end] == 0){
                start++;
                end--;
            }
        }
        return nums;
    }
};