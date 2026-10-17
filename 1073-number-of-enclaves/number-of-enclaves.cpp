
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1 && !visited[i][0]) {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if(grid[i][m-1] == 1 && !visited[i][m-1]) {
                q.push({i, m-1});
                visited[i][m-1] = 1;
            }
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !visited[0][j]) {
                q.push({0, j});
                visited[0][j] = 1;
            }
            if(grid[n-1][j] == 1 && !visited[n-1][j]) {
                q.push({n-1, j});
                visited[n-1][j] = 1;
            }
        }

        while(q.size() > 0) {
            auto temp = q.front();
            int row = temp.first;
            int col = temp.second;
            q.pop();

            if(row+1 < n && grid[row+1][col] == 1 && !visited[row+1][col]) {
                q.push({row+1, col});
                visited[row+1][col] = 1;
            }

            if(row-1 >= 0 && grid[row-1][col] == 1 && !visited[row-1][col]) {
                q.push({row-1, col});
                visited[row-1][col] = 1;
            }

            if(col+1 < m && grid[row][col+1] == 1 && !visited[row][col+1]) {
                q.push({row, col+1});
                visited[row][col+1] = 1;
            }

            if(col-1 >= 0 && grid[row][col-1] == 1 && !visited[row][col-1]) {
                q.push({row, col-1});
                visited[row][col-1] = 1;
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};
