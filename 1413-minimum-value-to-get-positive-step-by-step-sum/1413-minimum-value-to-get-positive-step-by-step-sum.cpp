class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int start = 0;
        int mini = 0;
        for(int i=0;i<nums.size();i++){
            start += nums[i];
            mini = min(start, mini);
        }
        return (mini<0) ? abs(mini)+1 : mini+1;
    }
};