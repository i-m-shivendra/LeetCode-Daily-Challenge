class Solution {
public:
    
    bool isSymmetric(int num){
        string s = to_string(num);
        int n = s.size();
        if(n%2 != 0){
            return false;
        }

        int leftSum = 0;
        int rightSum = 0;

        for(int i=0;i<n/2;i++){
            leftSum += s[i] - '0';
            rightSum += s[n-i-1] - '0';
        }

        return leftSum == rightSum;
    }
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        for(int i=low;i<=high;i++){
            if(isSymmetric(i)){
                result += 1;
            }
        }
        return result;
    }
};