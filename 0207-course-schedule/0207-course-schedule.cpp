class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto it : prerequisites){
            adjList[it[0]].push_back(it[1]);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it : adjList[i]){
                indegree[it]++;
            }
        }

        vector<int> vis(numCourses,0);
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int ans = 0;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans += 1;
            for(auto it : adjList[front]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans == numCourses;
    }
};