class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&image,vector<vector<int>>&visited,int n, int m){
        if (row < 0 || row >= n || col < 0 || col >= m ||
    visited[row][col] || image[row][col] == '0')
    return;
         visited[row][col]=1;
         //mark kar dia as visited;
         //ab baki age peeche ka dekh
         dfs(row+1,col,image,visited,n,m);
         dfs(row-1,col,image,visited,n,m);
         dfs(row,col+1,image,visited,n,m);
         dfs(row,col-1,image,visited,n,m);






    }
    int numIslands(vector<vector<char>>& grid) {



        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<char>>image=grid;

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, image, visited, n, m);
}

                }
            
        }

        return count;

        
        
    }
};