class Solution {
public:
    vector<int>dp;
    int f(vector<int>&nums,int n, int index){
        if(index>=n)return 0;

        if(dp[index]!=-1)return dp[index];


        int lena=nums[index]+f(nums,n,index+2);
        int nailena=f(nums,n,index+1);


        return dp[index]= max(lena,nailena);
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size()+1,-1);

        int index=0;
        int n=nums.size();
        return f(nums,n,index);
        
    }
};