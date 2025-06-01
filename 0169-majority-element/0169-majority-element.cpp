class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        int element;

        for(int i=0;i<n;i++){
            
            if(count == 0){
                element = nums[i];
                count = 1;
            }

            else if(nums[i] == element){
                count += 1;
            }

            else{
                count -= 1;
            }
        }
        
        int count1 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == element){
                count1 += 1;
            }
        }

        return (count1 > n/2) ? element : -1;
    }
};