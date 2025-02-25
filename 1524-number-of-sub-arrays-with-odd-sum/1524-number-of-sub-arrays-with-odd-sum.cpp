class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int MOD = 1e9 + 7;

        int n = arr.size();
        int ans = 0;
        int sum = 0;

        int oddCount = 0;
        int evenCount = 1;

        for(int i=0;i<n;i++){
            sum += arr[i];

            if(sum % 2 != 0){
                ans = (ans+evenCount) % MOD;
                oddCount++;
            }

            else{
                ans = (ans+oddCount) % MOD;
                evenCount++;
            }
        }
        return ans;
    }
};