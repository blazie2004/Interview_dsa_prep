class Solution {
public:
    
    bool ispossible(vector<int>&bloomDay,int m , int k,int mid){

        //ith day wala flower bloomday[i] ko grow karega
        int count=0;
        int b=0;
        //mid is the number of day;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]>mid){
                count=0;
                //count ko 0 kardo
            }
            else{
                count++;
                if(count==k){
                    b++;
                    count=0;
                }
                
            }
        }
        return b>=m;


    }
    int minDays(vector<int>& bloomDay, int m, int k) {


        int low=1;
        int high=INT_MAX/2;
        int ans=-1;


        while(low<=high){
            int mid=low+(high-low)/2;


            if(ispossible(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};