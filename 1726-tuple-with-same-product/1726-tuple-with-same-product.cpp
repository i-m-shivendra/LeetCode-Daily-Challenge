class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        unordered_map <int,int> mp;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }

        for(auto &it:mp)
        {
            int product = it.first;
            int freq = it.second;

            count += (freq * (freq-1) ) / 2;
        }
        return count*8;
    }
};