class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int ans=0;
        int n=nums.size();
        
        //sort the given array
        
        sort(nums.begin(),nums.end());
        
        for(int i=n-1;i>=2;i--)
        {
            int low=0;
            int high=i-1;
            
            while(low<high)
            {
                if(nums[low]+nums[high]>nums[i])
                {
                    ans=ans+(high-low);
                    high--;
                }
                else
                {
                    low++;
                }
             }
         }
        return ans;
        
    }
};