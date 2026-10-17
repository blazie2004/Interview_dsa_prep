
class Solution {
public:

    bool dfs(vector<vector<int>>& grid, vector<int>& color, int start, int curr_color) {
        color[start] = curr_color;

        for(auto it : grid[start]) {
            if(color[it] == -1) {
                if(!dfs(grid, color, it, 1 - curr_color)) {
                    return false;
                }
            }
            else if(color[it] == curr_color) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(!dfs(grid, color, i, 0)) {
                    return false;
                }
            }
        }

        return true;
    }
};
