class Solution {
public:
    string triangleType(vector<int>& nums) 
    {
        string ans="";

        if(nums[0]+nums[1]<=nums[2] || nums[1]+nums[2]<=nums[0] || nums[0]+nums[2]<=nums[1])
        {
            ans="none";
            return ans;
        }

        if(nums[0]==nums[1] && nums[1]==nums[2])
        {
            ans="equilateral";
            return ans;
        }
        
        else if(nums[0]==nums[1] || nums[1]==nums[2] || nums[0]==nums[2])
        {
            ans="isosceles";
            return ans;
        }

        else
        {
            ans="scalene";
            return ans;
        }
        return ans;
    }
};