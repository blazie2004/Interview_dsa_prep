class Solution {
public:
    int maxSubArray(vector<int>& nums) {


        //p1[i] is the maximum sum array ending at index i
        //best value of p1[i] can be  p1[i-1]+nums[i] or just nums[i]


        int curr=nums[0];
        int maxi=nums[0];

        for(int i=1;i<nums.size();i++){
            curr=max(nums[i],curr+nums[i]);
            maxi=max(maxi,curr);
        }
        return maxi;




    }
};