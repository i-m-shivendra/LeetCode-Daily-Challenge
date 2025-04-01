class Solution {
    int n;
public:

    long long solve(int i, vector<vector<int>>& questions, vector<long long>& dp){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        long long taken = questions[i][0] + solve(i+questions[i][1]+1, questions, dp);
        long long notTaken = solve(i+1, questions, dp);

        return dp[i] = max(taken, notTaken);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        vector <long long> dp(n+1, -1);
        return solve(0, questions, dp);
    }
};