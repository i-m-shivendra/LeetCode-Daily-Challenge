class Solution {
private:
   
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int ans = 0;
        int val = 0;
        unsigned int power = 1;

        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                ans += 1;
            }
        }

        for(int i=n-1;i>=0;i--){
            if(s[i] == '1'){
                if(val+power <= k){
                    val += power;
                    ans++;
                }
                power = power*2;
            }
            else{
                power = power*2;
            }

            if(power > k ) break;
        }
        return ans;
    }
};