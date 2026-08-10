class Solution {
public:
    int f(vector<vector<int>>&grid,int m,int n,int row,int col,vector<vector<int>>&dp){
        if(row>=m || col>=n)return INT_MAX/2;
        if(row==m-1 && col==n-1)return grid[row][col];

        if(dp[row][col]!=-1)return dp[row][col];

        int down=grid[row][col]+f(grid,m,n,row+1,col,dp);
        int right=grid[row][col]+f(grid,m,n,row,col+1,dp);

        return dp[row][col]= min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return f(grid,m,n,0,0,dp);
    }
};