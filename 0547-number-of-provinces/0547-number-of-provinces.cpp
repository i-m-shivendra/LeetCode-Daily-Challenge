class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList,
    vector<int>& visited){
        visited[node] = 1;

        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it,adjList,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        //Creation of adjacency list
        vector<vector<int>> adjList(V);

        //Initialisation of adjacency list
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        //Create a visited array
        vector<int> visited(V,0);

        int ans = 0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adjList,visited);
                ans += 1;
            }
        }
        return ans;
    }
};