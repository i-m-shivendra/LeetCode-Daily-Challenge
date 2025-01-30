class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Check if the graph is bipartite
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1 && !isBipartite(adj, color, i)) {
                return -1; // Graph is not bipartite
            }
        }

        // For each connected component, find the maximum number of groups
        int maxGroups = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                // Find all nodes in the current connected component
                vector<int> component;
                bfsComponent(adj, i, visited, component);

                // Find the maximum number of groups for this component
                int currentMax = 0;
                for (int node : component) {
                    currentMax = max(currentMax, bfsLevels(adj, node));
                }
                maxGroups += currentMax;
            }
        }

        return maxGroups;
    }

private:
    // Check if the graph is bipartite using BFS
    bool isBipartite(const vector<vector<int>>& adj, vector<int>& color, int start) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false; // Not bipartite
                }
            }
        }

        return true;
    }

    // Perform BFS to find all nodes in the connected component
    void bfsComponent(const vector<vector<int>>& adj, int start, vector<bool>& visited, vector<int>& component) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            component.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Perform BFS to determine the maximum number of levels (groups)
    int bfsLevels(const vector<vector<int>>& adj, int start) {
        queue<int> q;
        q.push(start);
        vector<int> level(adj.size(), -1);
        level[start] = 1;
        int maxLevel = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (level[neighbor] == -1) {
                    level[neighbor] = level[node] + 1;
                    maxLevel = max(maxLevel, level[neighbor]);
                    q.push(neighbor);
                }
            }
        }

        return maxLevel;
    }
};
