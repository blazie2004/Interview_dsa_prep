class Solution {
public:
    void dfs(int start, vector<vector<int>>& adjls, vector<int>& visited) {
        visited[start] = 1;

        for (auto it : adjls[start]) {
            if (!visited[it]) {
                dfs(it, adjls, visited);
            }
            
        }
       
        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adjls(n);

      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                }
            }
        }

        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adjls, visited);
            }
        }

        return count;
    }
};