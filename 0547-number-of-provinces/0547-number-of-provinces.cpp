class Solution {
private:
   void dfs(int node, vector<vector<int>>& adjList,
   vector<int>& visited){
    visited[node] = 1;

    for(auto it : adjList[node]){
        if(!visited[it]){
            dfs(it, adjList, visited);
        }
    }
    
   }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V  = isConnected.size();

        //Defining an adjacency list
        vector<vector<int>> adjList(V);

        //Converting adjacency matrix to List
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        //Declaring an visited array
        vector<int> visited(V, 0);

        //Declaring count variable
        int count = 0;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, adjList, visited);
                count += 1;
            }
        }

        return count;
    }
};