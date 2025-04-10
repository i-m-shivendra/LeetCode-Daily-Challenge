class Solution {
public:
    int numberOfPowerfulInt(int start, int finish, int limit, string suffix) {
        auto countPowerfulUpTo = [&](int num) -> int {
            string numStr = to_string(num);
            int suffixLen = suffix.size();
            int prefixLen = numStr.size() - suffixLen;

            if (prefixLen < 0) return 0;

            vector<vector<int>> dp(prefixLen + 1, vector<int>(2, 0));

            dp[prefixLen][0] = 1;
            string suffixFromNum = numStr.substr(prefixLen);
            dp[prefixLen][1] = stoi(suffixFromNum) >= stoi(suffix) ? 1 : 0;

            for (int i = prefixLen - 1; i >= 0; --i) {
                int digit = numStr[i] - '0';
                dp[i][0] = (limit + 1) * dp[i + 1][0];

                if (digit <= limit) {
                    dp[i][1] = digit * dp[i + 1][0] + dp[i + 1][1];
                } else {
                    dp[i][1] = (limit + 1) * dp[i + 1][0];
                }
            }

            return dp[0][1];
        };

        return countPowerfulUpTo(finish) - countPowerfulUpTo(start - 1);
    }
};