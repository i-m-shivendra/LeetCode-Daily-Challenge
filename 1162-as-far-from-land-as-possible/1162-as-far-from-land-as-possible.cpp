class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int,int>> q;

        //visited array
        vector<vector<int>> visited(grid);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == 1){
                    q.push({i,j});
                }
            }
        }

        if(q.empty() || q.size() == n*n){
            return -1;
        }

        vector<pair<int,int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto[x,y] = q.front();
                q.pop();

                for(auto[dx,dy] : dir){
                    int i = x + dx;
                    int j = y + dy;

                    if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == 0) {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            ans += 1;
        }
        return ans-1;
    }
};