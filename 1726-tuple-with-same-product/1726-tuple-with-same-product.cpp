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
                int product = nums[i] * nums[j];
                unordered_set <int> st;

                for(int k=i+1;k<j;k++)
                {
                    if(product % nums[k] == 0)
                    {
                        int d = product / nums[k];

                        if(st.count(d))
                        {
                            count++;
                        }
                        st.insert(nums[k]);
                    }
                }
            }
        }
        return count*8;
    }
};