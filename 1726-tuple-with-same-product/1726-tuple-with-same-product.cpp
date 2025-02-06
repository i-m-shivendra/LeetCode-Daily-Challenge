class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                for(int k=i+1;k<j;k++)
                {
                    for(int l=j-1;l>k;l--)
                    {
                        if(nums[i]*nums[j] == nums[k]*nums[l])
                            {
                                count += 1;
                            }
                    }
                }
            }
        }
        return count*8;
    }
};