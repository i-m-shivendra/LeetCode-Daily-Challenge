class Solution {
public:
    int getDigitSum(int num)
    {
        int sum = 0;
        while(num != 0)
        {
            int lD = num % 10;
            sum += lD;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        unordered_map <int,int> mp;

        for(int i=0;i<n;i++)
        {
            int digitSum = getDigitSum(nums[i]);

            if(mp.count(digitSum))
            {
                result = max(result,nums[i]+mp[digitSum]);
            }

            mp[digitSum] = max(mp[digitSum],nums[i]);
        }
        return result;
    }
};