class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n=nums.size();

        int low=0;
        int high=n-1;
        int index_f=-1;
        int index_l=-1;


        while(low<=high){

            int mid =low+(high-low)/2;

            if(nums[mid]>target){
                // jaha aye vo bada hai 
                high=mid-1;
            }
            else if (nums[mid]<target){
                low=mid+1;
            }
            else{
                //we get that element 
                index_f=mid;
                high=mid-1;
            }
        }

        low=0;high=n-1;
        while(low<=high){
            int mid= low+(high-low)/2;

            if(nums[mid]>target){
                high=mid-1;
            }
            else if (nums[mid]<target){
                low=mid+1;
            }
            else{
                index_l=mid;
                low=mid+1;
            }
        }
        vector<int>ans;
        ans.push_back(index_f);
        ans.push_back(index_l);

        return ans;
        
    }
};