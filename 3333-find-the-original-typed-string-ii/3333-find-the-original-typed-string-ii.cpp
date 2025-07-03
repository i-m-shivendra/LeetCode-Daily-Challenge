class Solution 
{
public:
    const int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) 
    {
        // Step 1: Group consecutive letters into their sizes
        vector<int> groups = getConsecutiveLetters(word);

        // Step 2: Multiply group sizes to get total combinations
        long long totalCombinations = 1;
        for (int group : groups) 
        {
            totalCombinations = (totalCombinations * group) % MOD;
        }

        // Step 3: If length of original string is already >= k, return all combinations
        if (k <= groups.size()) 
        {
            return totalCombinations;
        }

        // Step 4: Initialize DP array
        vector<int> dp(k, 0);
        dp[0] = 1;  // Base case: one way to form an empty string

        // Step 5: DP logic to count invalid combinations (< k length)
        for (int i = 0; i < groups.size(); ++i) 
        {
            int group = groups[i];
            vector<int> newDp(k, 0);
            int windowSum = 0;

            // Step 5.1: For each position j >= i (need at least i groups), calculate ways
            for (int j = i; j < k; ++j) 
            {
                newDp[j] = (newDp[j] + windowSum) % MOD;
                windowSum = (windowSum + dp[j]) % MOD;

                if (j >= group) 
                {
                    windowSum = (windowSum - dp[j - group] + MOD) % MOD;
                }
            }

            dp = newDp;
        }

        // Step 6: Count invalid combinations (length < k)
        int invalidCombinations = 0;
        for (int count : dp) 
        {
            invalidCombinations = (invalidCombinations + count) % MOD;
        }

        // Step 7: Subtract invalid from total to get valid combinations
        return (totalCombinations - invalidCombinations + MOD) % MOD;
    }

private:
    vector<int> getConsecutiveLetters(const string& word) 
    {
        vector<int> groups;
        if (word.empty())
        {
            return groups;
        } 

        int count = 1;
        for (int i = 1; i < word.size(); ++i) 
        {
            if (word[i] == word[i - 1]) 
            {
                ++count;
            } 
            else 
            {
                groups.push_back(count);
                count = 1;
            }
        }

        groups.push_back(count);
        return groups;
    }
};