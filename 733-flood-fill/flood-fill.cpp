
class Solution {
public:
    void dfs(vector<vector<int>>& cop, int row, int col,
             int n, int m, int color, int source_color) {

        if (row < 0 || row >= n || col < 0 || col >= m ||
            cop[row][col] != source_color || cop[row][col] == color) {
            return;
        }

        cop[row][col] = color;

        dfs(cop, row + 1, col, n, m, color, source_color);
        dfs(cop, row, col + 1, n, m, color, source_color);
        dfs(cop, row - 1, col, n, m, color, source_color);
        dfs(cop, row, col - 1, n, m, color, source_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> cop = image;
        int source_color = cop[sr][sc];

        dfs(cop, sr, sc, n, m, color, source_color);

        return cop;
    }
};
