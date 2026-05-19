class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {


        //range sum 
        // p[j]-p[i-1]==k==p[i....j]
        // so p here is prefix sum 
        // we need count of all the subarrays 
        //what we have p[j]-k if this sum is encountered before we have a range sum
        // increase the count


        unordered_map<int,int>mp;

        int sum=0;
        int count=0;
        // mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            if(mp.find(sum-k)!=mp.end()){
                //if present 
                count=count+mp[sum-k];
            }
            if(sum==k)count++;
            
            mp[sum]++;
        }
        return count;
    }
};