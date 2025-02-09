class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_set <int> st;

        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                st.insert(nums[i]);
            }
        }
        return st.size();
    }
};