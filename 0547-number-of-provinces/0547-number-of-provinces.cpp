class Solution {
private:
  void bfs(int node,vector<int>& visited, 
         vector<vector<int>>& adjList){
            visited[node] = true;

            queue<int> q;
            q.push(node);
            while(!q.empty()){
                int front = q.front();
                q.pop();

                for(auto it : adjList[front]){
                    if(!visited[it]){
                        visited[it] = 1;
                        q.push(it);
                    }
                }
            }
         }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<vector<int>> adjList(N);

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(N+1, 0);
        int count = 0;

       for(int i=0;i<N;i++){
        if(!visited[i]){
            bfs(i,visited,adjList);
            count++;
        }
       }
        return count;
    }
};