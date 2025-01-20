// class Solution {
// public:
//     bool checkRowPainted(vector<vector<int>>& mat, int row) {
//         for(int col = 0; col < mat[0].size(); col++) {
//             if(mat[row][col] > 0) { //not painted
//                 return false;
//             }
//         }

//         return true;
//     }

//     bool checkColPainted(vector<vector<int>>& mat, int col) {
//         for(int row = 0; row < mat.size(); row++) {
//             if(mat[row][col] > 0) { //not painted
//                 return false;
//             }
//         }

//         return true;
//     }

//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();

//         unordered_map<int, pair<int, int>> mp; //stores value to cell-coordinate [i][j]

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 int val = mat[i][j];
//                 mp[val] = {i, j};
//             }
//         }

//         for(int i = 0; i < arr.size(); i++) {
//             int val = arr[i];

//             auto [row, col] = mp[val];
//             mat[row][col] *= -1; //painted

//             if(checkRowPainted(mat, row) || checkColPainted(mat, col)) {
//                 return i;
//             }
//         }

//         return -1; 
//     }
// };

//Approach - 2 (Better Approach)
//T.C : O(m*n)
//S.C : O((m*n) + m + n)
class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> mp; //stores value to cell-coordinate [i][j]

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int val = mat[i][j];
                mp[val] = {i, j};
            }
        }

        vector<int> rowCountPaint(m, 0); //[i] = how many painted in row i
        vector<int> colCountPaint(n, 0); //[i] = how many painted in col i

        for(int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            auto [row, col] = mp[val];

            rowCountPaint[row]++;
            colCountPaint[col]++;

            if(rowCountPaint[row] == n || colCountPaint[col] == m) {
                return i;
            }
        }
        return -1;
    }
};