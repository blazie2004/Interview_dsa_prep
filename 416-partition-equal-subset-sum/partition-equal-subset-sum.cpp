class Solution {
public:
    bool helper(int index, vector<int>& nums, int target, int n, vector<vector<int>>& dp) {
        if (target < 0 || index >= n) return false;
        if (target == 0) return true;
     
        
      

       
        if (dp[index][target] != -1) return dp[index][target];

     
        bool left = helper(index + 1, nums, target - nums[index], n, dp);
        bool right = helper(index + 1, nums, target, n, dp);

      
        return dp[index][target] = left || right;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

      
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

       
        if (sum % 2 != 0) return false;
        else {
           
            vector<vector<int>> dp(201, vector<int>(sum+1, -1));
            int s=sum/2;
            
            return helper(0, nums, s, n, dp);
        }
    }
};