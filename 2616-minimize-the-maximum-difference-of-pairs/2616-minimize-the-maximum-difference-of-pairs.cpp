class Solution {
private:
    bool check(vector<int>&nums, int p, int mid){
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1] - nums[i] <= mid){
                count += 1;
                i++;
            }
        }
        return count >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        int ans = -1;
        sort(nums.begin(),nums.end());

        int start = 0;
        int end = nums[n-1] - nums[0];

        while(start <= end){
            int mid = start + (end-start)/2;

            if(check(nums,p,mid)){
                ans = mid;
                end = mid-1;
            }

            else{
                start = mid+1;
            }
        }
        return ans;
    }
};