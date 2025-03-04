class Solution {
public:

    int solve(int n, int power){
        if(n == 0){
            return true;
        }

        if(pow(3,power) > n){
            return false;
        }

        bool power_ko_le_lo = solve(n-pow(3,power), power+1);

        bool power_ko_mat_lo = solve(n, power+1);

        return power_ko_le_lo || power_ko_mat_lo;
    }

    bool checkPowersOfThree(int n) {
        return solve(n, 0);
    }
};