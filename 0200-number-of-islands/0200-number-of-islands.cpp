class Solution {
private:
   void dfs(int row,int col,vector<vector<int>>& visited,
   vector<vector<char>>& grid){
    visited[row][col] = 1;

    int n = grid.size();
    int m = grid[0].size();

    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    for(int i=0;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol <m
        && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
            dfs(nrow,ncol,visited,grid);
        }
    }    
       
   }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i,j,visited,grid);
                    ans += 1;
                }
            }
        }
        return ans;
    }
};