class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;
        vector<int> adj[n];

        for (auto it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }

        vector<int> topo;
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                indegree[adj[i][j]]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int ele = q.front();
            q.pop();

            topo.push_back(ele);

            for (auto it : adj[ele]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo.size() == n;
    }
};