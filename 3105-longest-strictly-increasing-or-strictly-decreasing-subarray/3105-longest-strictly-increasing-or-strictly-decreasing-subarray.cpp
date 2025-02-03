class Solution
{
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        int increasing=1, decreasing=1, max_increasing=1, max_decreasing=1;

        for(int i=1, n=nums.size(); i<n; i++)
        {
            if(nums[i-1]<nums[i]) increasing++;
            else increasing=1;

            if(nums[i-1]>nums[i]) decreasing++;
            else decreasing=1;

            max_increasing=max(max_increasing, increasing);
            max_decreasing=max(max_decreasing, decreasing);
        }

        return max(max_increasing, max_decreasing);
    }
};