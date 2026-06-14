class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int s=0;
        int count=0;

        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(mp.find(s-goal)!=mp.end()){
                //mila
                count+=mp[s-goal];

            }
            mp[s]++;
            
            
        }
        return count;
        
    }


    
};