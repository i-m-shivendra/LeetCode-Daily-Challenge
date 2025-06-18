class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto it : prerequisites){
            adjList[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it : adjList[i]){
                indegree[it]++;
            }
        }
        
        vector<int> ans;

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans.push_back(front);

            for(auto it : adjList[front]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return (ans.size() == numCourses) ? ans : vector<int>();
    }
};