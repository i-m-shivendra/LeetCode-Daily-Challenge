class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int N = 26;

    vector<vector<long long>> multiply_Matrices(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int n = A.size();
        vector<vector<long long>> ans(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return ans;
    }

    vector<vector<long long>> matrix_Exponentiation(vector<vector<long long>>& A, long long power) {
        int n = A.size();
        vector<vector<long long>> ans(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            ans[i][i] = 1;
        }

        while (power > 0) {
            if (power % 2 == 1) {
                ans = multiply_Matrices(ans, A);
            }
            A = multiply_Matrices(A, A);
            power /= 2;
        }

        return ans;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Step 1: Build transformation matrix
        vector<vector<long long>> Transformation_matrix(N, vector<long long>(N, 0));
        for (int i = 0; i < N; ++i) {
            int spread = nums[i];
            for (int j = 1; j <= spread; ++j) {
                int next = (i + j) % N;
                Transformation_matrix[i][next] = (Transformation_matrix[i][next] + 1) % MOD;
            }
        }

        // Step 2: Count initial frequencies
        vector<long long> freq(N, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 3: Raise transformation matrix to power t
        vector<vector<long long>> Transformation_matrix_pow = matrix_Exponentiation(Transformation_matrix, t);

        // Step 4: Multiply T^t with initial frequency vector
        vector<long long> ans(N, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ans[j] = (ans[j] + freq[i] * Transformation_matrix_pow[i][j]) % MOD;
            }
        }

        // Step 5: Compute final total
        long long total = 0;
        for (long long val : ans) {
            total = (total + val) % MOD;
        }

        return (int)total;
    }
};