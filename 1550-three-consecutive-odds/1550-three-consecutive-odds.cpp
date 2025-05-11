class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n-2;i++){
            if(arr[i] % 2 == 1 && arr[i+1] % 2 == 1  && 
            arr[i+2] % 2 == 1){
                    ans += 1;
              }
        }
        return ans;
    }
};